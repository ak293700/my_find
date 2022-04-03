CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -D_DEFAULT_SOURCE 

#debug
#CFLAGS += -g

C_FILE = ./src/c_file/

MAIN_SRC = ./src/main.c
MAIN_OBJS = main.o

SRC_EXE = myfind

SRC = $(C_FILE)ls.c $(C_FILE)stack.c $(C_FILE)fifo.c $(C_FILE)ast.c
SRC += $(C_FILE)node.c $(C_FILE)type.c $(C_FILE)tools.c
SRC += $(C_FILE)ast_functional.c $(C_FILE)arg_operation.c

SRC_OBJS = ls.o stack.o fifo.o ast.o node.o type.o tools.o ast_functional.o
SRC_OBJS += arg_operation.o

TEST_EXE = tests.out
TEST = ./tests/easy_tests.c
TEST_OBJS = easy_tests.o 

all: my_find

.PHONY: my_find
my_find: $(SRC_OBJS) $(MAIN_OBJS)
	@#echo "my_find"
	$(CC) $(SRC_OBJS) $(MAIN_OBJS) -o $(SRC_EXE)

$(MAIN_OBJS): $(MAIN_SRC)
	@#echo "main_objs"
	$(CC) -c $(CFLAGS) $(MAIN_SRC)


$(SRC_OBJS): $(SRC)
	@#echo "src_objs"
	$(CC) -c $(CFLAGS) $(SRC)


#Create *_test.o
$(TEST_OBJS): $(TEST)
	@#echo "test_objs"
	$(CC) -c $(CFLAGS) $(TEST)

.PHONY: check
check: $(SRC_OBJS) $(TEST_OBJS)
	@#echo "check"
	$(CC) $(TEST_OBJS) $(SRC_OBJS) -lcriterion -o $(TEST_EXE)
	./$(TEST_EXE)


.PHONY: clean
clean:
	@#echo "clean"
	${RM} $(TEST_EXE) $(TEST_OBJS) $(MAIN_OBJS)
	${RM} $(SRC_EXE) $(SRC_OBJS)
