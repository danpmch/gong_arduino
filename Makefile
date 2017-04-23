
SRC=gong.ino

all:
	arduino --verify $SRC

install:
	arduino --upload $SRC

