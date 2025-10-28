# Bridges Game Data Project

## Overview
This C++ project uses the BRIDGES library to access and display IGN game data. The program connects to the Bridges API and retrieves information about video games, displaying details like title, platform, rating, and genres.

## Current State
The project is fully functional and successfully prints information about the first game in the dataset.

## Recent Changes
- **October 28, 2025**: Set up complete Bridges library environment
  - Installed Bridges C++ library from GitHub
  - Installed rapidjson dependency for JSON parsing
  - Configured curl for API communication
  - Created build script (run.sh) with proper compilation flags
  - Set up workflow to compile and run the program

## Project Architecture

### Dependencies
- **Bridges C++ Library**: Educational library for data structure visualization
- **RapidJSON**: JSON parsing library
- **libcurl**: HTTP communication with Bridges API

### Key Files
- `main.cpp`: Main program that fetches and displays game data
- `run.sh`: Build and run script with proper include paths and linker flags
- `Games.h` / `Games.cpp`: Currently empty, reserved for future game-related code

### Environment Variables
- `SECRET_HOLDING_USER_ID`: Bridges user ID (currently set)
- `SECRET_HOLDING_API_KEY`: Bridges API key (currently set)

## Building and Running
The project uses a custom build script because the Bridges library requires specific compilation flags:
```bash
./run.sh
```

This compiles with:
- C++14 standard
- Local include paths for Bridges headers and rapidjson
- curl include and library paths from curl-config

## User Preferences
None specified yet.
