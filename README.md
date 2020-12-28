
# Beth Yw?

You're part of a development team that is building a chatbot that can answer
"what is…?" questions in relation to the Open Data available from the Welsh 
Government. For this project, you will need to parse data files, storing 
infomration as objects, and calculating statistics.

Later stages of the project will hook into the live data feeds from the
Stats Wales website, but for now we are going to work with offline files. We're also only going to look at geographic-organised data (i.e. data organised by area) for simplicity.

## About the provided code 

For this coursework you will be working entirely with offline files provided in 
the _data_ directory. You should use these files in your coursework—do not 
modify, update, or replace them. When marking your coursework, I will use fresh
copies of the files I have provided with the coursework specification.

A number of header and implementation files have been written for you. These detail the code you will have to implement in this coursework.

Do not change any of the provided **public** functions in the header files, although you can change/modify other elements in the header files (indeed, you may have to for the coursework).  During marking, automatic tests will call your implemented functions, using the public API you have been given. If there is a compile error because you changed a function prototype, you will fail the test and lose marks. 

You are responsible for making sure the code you implement in the coursework meets the requirements. Anywhere where you have to write code, there is a TODO commment. Read it, think about it, and implement it. You should also work out ways to test your code with different inputs etc. to make sure it works.

I have provided a number of tests using the Catch2 framework, which we covered in a lecture. I will be testing your coursework with these tests, plus some additional tests I will not share with you. It is your job to make sure you think of all the issues your code may face and to write good, clean, organised code that catches and deals with unexpected situations.

### Data files

The following files of data are stored in the _data_ directory. I have given 
the URL where I downloaded these files from. A reminder: do not replace or 
modify the file I have provided you—your coursework will be marked with a 
copy of the specific version given.

* areas.csv - A manually created list of areas in Wales
* popu1009.json - [Population Density](http://open.statswales.gov.wales/en-gb/dataset/popu1009)


### Libraries used

The following libraries have been included in this coursework:

* [Catch2 Unit testing framework](https://github.com/catchorg/Catch2)
* [CXXOpts - Lightweight C++ command line option parser](https://github.com/jarro2783/cxxopts)
* [JSON for Modern C++](https://github.com/nlohmann/json)

## Building your code

The code is written for C++ 17. A sample build script has been included in _build.sh_, as a recommendation, and will be used in testing your code. If you wish to build the code your own way, this is fine.

The key thing to note is that when building, you should build with all warnings printed out (`-Wall`) as your program must not have any compiler warnings.

## Testing your code

_build.sh_ also includes the code for testing your coursework with the Catch2 library. There are a number of tests in the _tests_ directory, and you can compile and test your code with any of these by calling `./build.sh testN` where `n` is a number of a test. Note that _build.sh_ will product the object file for catch2 if it does not exist in the _bin_ directory. 

## Runtime arguments

Your program should take a number of arguments:

 -f <dirname> 
              Name of the data directory (you can vary this to test your code with different variations of the data)
 -d [<dataset>, <dataset>, ..., <dataset>] 
              List of specific comma-separated datasets to parse
 -a [<area>, <area>, ... <area>|all]
              List of specific areas to collate statistics for, or all areas (if ommitted assume all)
 -m <measure>
              Specific meaausure to examine (optional)
 -y <year>
              Specific year to examine (optional)

If the data directory is invalid or you cannoy read an source file, you should print out an error message and abort.

There are a number of sample outputs in the _sample-outputs_ directory for the expected outputs (both in situations where it works and doesn't work):

* 0.txt gives the error output for bethyw -f nonexistantdir (assuming nonexistantdir is a non-existant directory)
* 1.txt gives the successful output for bethyw -f data -d popdensity

## Coursework tasks

This coursework can feel like quite a lot at first, but the reality is you have to write very little code, but figuring out the layout of an existing program given to you is half the challenge! When you work in industry, you will rarely be starting with a clean sheet. 

There are a number of tasks you should go about completing for this coursdework. As a suggestion, I've ordered them in the way I think you should tackle them. 

1. Reading in the areas.csv file
   The first task you should do is read in the _areas.csv_ file. In _main.cpp_, the code that calls the right functions has already been written for you.
