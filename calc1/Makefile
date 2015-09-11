#-----------------------------------------------#
# GNU Cコンパイラを使用するUNIXシステム用のMakefile
#-----------------------------------------------#
CC=gcc
#CFLAGS=-g -D__USE_FIXED_PROTOTYPES__ -ansi
CFLAGS=-D__USE_FIXED_PROTOTYPES__ -ansi
#
# コンパイラフラグ：
#  -g                         -- デバッグ可能
#  -Wall                      -- すべての警告をオン（このプログラム中ではバグを見逃すため使用しない）
#  -D__USE_FIXED_PROTOTYPES__ -- コンパイラに適切なヘッダの使用を強制
#  -ansi                      -- GNUの拡張は使用しない。ANSI Cのみ

all: calc1 calc2

calc1: calc1.c
				$(CC) $(CFLAGS) -o calc1 calc1.c

calc2: calc2.c
				$(CC) $(CFLAGS) -o calc2 calc2.c

clean:
				rm -f calc1 calc2
