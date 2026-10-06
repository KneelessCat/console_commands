# Developing on Linux, so variables won't work on other platforms

# Get all .c files
SOURCE = $(wildcard src/*.c)

# Using values from src/*.c files, create objects
# patsubst is looking for patterns, substituting those patterns with something else
# So for each .c file in src/ it is creating a respective .o file in build/
# We use % to match the file name, so it remains the same for .c and .o files
OBJECTS = $(patsubst src/%.c, build/%.o, $(SOURCE))

# Variables stipulating directories and commands
BUILD = build/
BIN = bin/
MKDIR = mkdir -p
RM = rm -f
RMDIR = rm -rf

# our final program
TARGET = $(BIN)ccmds

DEPS = $(OBJECTS:.o=.d)
-include $(DEPS)

all: $(TARGET)


# Must have a bin/build directory before we make objects
# Colon seperates prerequisites (on the right), the | means that if they are updated it will not rebuild what's on the left
$(OBJECTS): | $(BIN) $(BUILD)

# Must make the build/ and bin/ directories
$(BUILD):
	$(MKDIR) $(BUILD)

$(BIN):
	$(MKDIR) $(BIN)


# parameters
# 	-MMD = essentially takes all .o files and creates .d files. Outputs only mentions user header files
# 	-MP = makes a phony target for each dependency (a task, not an actual file), causes each dependency (other than main file) to depend on nothing. Gets rid of errors with make that occur when header files are removed without updating makefile to match
# 	-MF $(@:.o=.d) = for each .o file, writes a .d file with dependencies. @ is what does this replacement
# 	-c = compile without linking
# 	-wall = helps with debugging (turns on all errors that can be told about)
# 	-g = inclued proper variable names and functions, see line numbers, and source as stepping through the executable in a produced core dump file(?)
# 	$< refers to the first needed prerequisite (in this case the .c file)
# 	$@ refers to the target, the .o file
build/%.o: src/%.c
	gcc -MMD -MP -MF $(@:.o=.d) -c -Wall -g $< -o $@


$(TARGET): $(OBJECTS) | $(BIN)
	$(RM) $(TARGET)
	gcc -Wall -g $(OBJECTS) -o $(TARGET)

# We can do make clean if we want to build the project form scratch
clean:
	$(RMDIR) $(BUILD)
	$(RM) $(TARGET)

