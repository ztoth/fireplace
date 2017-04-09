# project
TARGET   = fireplace

# directories
SRCDIR	 = src
LIBDIR	 = lib

# main entry point
all .DEFAULT:
	pio run -e $@

# clean up object files
.PHONEY: clean
clean:
	pio run -t clean
