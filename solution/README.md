
# Beth Yw?

You're part of a development team that is building a chatbot that can answer "what is…?" questions in relation to the Open Data available from the Welsh Government. For this project, you will need to parse data files, storing information as objects, and calculating statistics.

Later stages of the project will hook into the live data feeds from the Stats Wales website, but for now we are going to work with offline files. We're also only going to look at geographic-organised data (i.e. data organised by area) for simplicity.


## What you have been given…

For this coursework you will be working entirely with offline files of statistics taken from the Stats Wales website, and provided in the _data_ directory. You should use these files in your coursework, but DO NOT modify, update, or replace them. When marking your coursework, I will use fresh copies of the files I have provided with the coursework specification.

A number of header and implementation files have been partially written for you, but you must now finish the implementation. Fortunately, there are comments throughout to help you do this. **Do not change the public API of any class or function**, as these will be called during the marking. If you have changed any function from what was provided, your code will fail the test and you will lose marks.

You are responsible for making sure the code you implement in the coursework meets the requirements set out in the comments. Read each comment, think about it, and implement it. If you do not understand comments, ask on the Coursework forum in Canvas or in labs.

You should also work out ways to test your code with different inputs etc. to make sure it works. I have provided a number of tests using the Catch2 framework, which we covered in a lecture. I will be testing your coursework with these tests, plus additional tests. It is your job to make sure you think of all the issues your code may face and to write good, clean, organised code that catches and deals with unexpected situations. Feel free to write additional tests for your code, and include these in your submission.


### Data files

The following data files are stored in the _data_ directory. I have given the URL where I downloaded these files from. A reminder: do not replace or modify the file I have provided you—your coursework will be marked with a copy of the specific version given.

* areas.csv - A manually created list of areas in Wales
* popu1009.json - [Population Density by local authority](http://open.statswales.gov.wales/en-gb/dataset/popu1009)
  * Note that a bug on the Stats Wales website truncates this data nad misses of many of the areas, for this coursework we don't worry about it
* econ0080.json - [Active businesses by area and year](https://statswales.gov.wales/Catalogue/Business-Economy-and-Labour-Market/Businesses/Business-Demography/activebusinessenterprises-by-area-year)
* envi0201.json - [Air Quality Indicators, by Local Authority](https://statswales.gov.wales/Catalogue/Environment-and-Countryside/Air-Quality/airqualityindicators-by-localauthority)
  * This dataset annoyingly stores data as a string, so you will have to convert in your code
* trans0152.json - [Rail passenger journeys by Local Authority and year](https://statswales.gov.wales/Catalogue/Transport/rail/rail-transport/railpassengerjourneys-by-localauthority-year)
  * This file had incomplete area codes so I have fixed these in the downloaded file
  * Also, the stats aren't collected calendar year (i.e. the original year codes were, e.g. 2002-03), but I changed that for this coursework
  * This is a special dataset — there is only one measure in it, which is hardcoded into datasets.h. I recommend completing this one last!
* complete-popu1009.csv - This is a CSV version of popu1009.json. The StatsWales website produces invalid CSV files by default and does not include authority codes. I've parsed and produced this file. Replace popu1009.json with this one. 

### Third-party libraries used

The following libraries have been included in this coursework:

* [Catch2 Unit testing framework](https://github.com/catchorg/Catch2)
* [CXXOpts - Lightweight C++ command line option parser](https://github.com/jarro2783/cxxopts)
* [JSON for Modern C++](https://github.com/nlohmann/json)

Catch2 is provided to help you test your code, as we covered in the lecture.

Some use of CXXOpts has been included, but you will have to write additional code using this library to fully implement your coursework.

You should use the JSON for Modern C++ library in your coursework, unless you are really, really, confident you can parse JSON another way. I have provided some tips for using this library, but if you are confident of another way, then you may use that. But note that your code will still face the same automatic tests!

### Test files

A number of tests have been included that test a range of functionality in your coursework.


## Building your coursework

I will be testing your code using C++17, which means you can make use of many newer features in C++ (but you do not have to). A sample build script has been included as _build.sh_. This build script can build either the 'main' version of your coursework, or one integrated with a specified Catch2 test script. To build your coursework, simply execute the _build.sh_ file using the command `./build.sh`.

If you wish to build the code your own way, this is fine, but when it comes to marking, I'll be using a script similar/compatible with the one provided. The key thing to note is that when building your coursework, you should also build with all warnings printed out (`-Wall`) as your program must not have any compiler warnings.


## Unit testing your code

As stated above, _build.sh_ includes code for testing your coursework with the Catch2 library and the tests in the _tests_ directory. You can compile  your code with any of these tests by calling `./build.sh testN` where `N` is the number of the test (matching the filename in _tests_). Note that _build.sh_ will produce the object file for catch2 if it does not exist in the _bin_ directory.

Upon successful compilation, there will be a binary executable, _bethyw-test_ in the _bin_ directory. Execute this file to run the test.


## Running your coursework

Your program should take a number of arguments (only the first has been implemented for you!):

```
-d <directory> 
             Name of the data directory (you can vary this to test your code with different variations of the data)
-d [<dataset>, <dataset>, ..., <dataset>] 
             List of specific comma-separated datasets to parse
-a [<area>, <area>, ... <area>|all]
             List of specific areas to collate statistics for, or all areas (if omitted assume all)
-m <measure>
             Specific measure to examine (optional)
-y <year>
             Specific year to examine (optional)
```

If the data directory is invalid or you cannot read an source file, you should print out an error message and abort.

There are a number of sample outputs in the _sample-outputs_ directory for the expected outputs (both in situations where it works and doesn't work):

* 0.txt gives the error output for `bethyw -f nonexistantdir` (assuming `nonexistantdir` is a non-existant directory)
* 1.txt gives the successful output for `bethyw -f data -d popdensity`


## Coursework tasks

This coursework can feel like quite a lot at first, but the reality is you have to write very little code, but figuring out the layout of an existing program given to you is half the challenge! When you work in industry, you will rarely be starting with a clean sheet. 

There are a number of tasks you should go about completing for this coursework. As a suggestion, I've ordered them in the way I think you should tackle them (and coincidently, in the order of the unit tests!)

#### 1. Reading in the _areas.csv_ file
The first task you should do is read in the _areas.csv_ file. In _main.cpp_, the code that calls the right functions has already been written for you, but you will have to edit the `sources.h` and `sources.cpp`. These two files are
responsible only for opening/retrieving sources.

* Your program should be called with the `-f <directory>` arguments, and if `<directory>` is valid and `areas.csv` exists in that directory, it should load it.
* If these arguments are not provided, print out the help information.
* If _areas.csv_ is not a valid file, print out the following and then abort:
```
<directory>/areas.csv error:
InputFile::import: Failed to open file
```

#### 2. Parsing _areas.csv_ 
Next you will need to parse _areas.csv_. This will require looking at the _datasets.h_ and _data.cpp_ files, both of which have a lot of comments to read through. Do that first.

As you should see, the parsing is triggered through the `populate()` function, which takes a stream and an enum of the type of data to be parsed. For your benefit, this enum has been provided at the top of of _datasets.h_. `populate()` should hand off the parsing to `populateFromAuthorityCodeCSV()` and `populateFromStatsWalesMultiMeasureJSON()`, depending on the enum value. You will have to implement all three of these functions eventually, although initially just the first two to parse _areas.csv_.

To implement `populateFromAuthorityCodeCSV()`, you will have to implement the functions for the `Area` class in _data.cpp_ too. Read the TODO comments in each function and implement them appropriately.

