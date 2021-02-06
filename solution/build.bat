@ECHO off

SET bin_dir=bin
SET tests_dir=tests
SET source_files=src\bethyw.cpp src\input.cpp src\areas.cpp src\area.cpp src\measure.cpp
SET main_file=main.cpp
SET executable=%bin_dir%\bethyw.exe

COPY bin\bethyw2.exe bin\bethyw.exe

IF "%1"=="" GOTO compile

SET testStr=%1%
SET testStr=%testStr:~0,4%
IF %testStr%==test (
  SET source_files=%source_files% %tests_dir%\%1%.cpp
  SET main_file=%bin_dir%\catch.o
  SET executable=%bin_dir%\bethyw-test.exe

  IF NOT EXIST %bin_dir%\catch.o (
     g++ --std=c++11 -c libs\catch2\catch_main.cpp -o %bin_dir%\catch.o
  )
)

:compile
IF NOT EXIST %bin_dir% MKDIR %bin_dir%
IF EXIST %executable% DEL %executable%
g++ --std=c++14 -Wall %source_files% %main_file% -o %executable%

:end
