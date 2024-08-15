NAME        = Pattern_saver

INC_DIR     = inc/
SRC_DIR     = src/
OBJ_DIR     = obj/
RAYLIB_LIB  = inc/raylib/src/libraylib.a

OBJ_DIR     = obj/
RAYLIB_LIB  = inc/raylib/src/libraylib.a

CC          = c++
CFLAGS      = -g -Wall -Wextra -Werror -std=c++11 -I$(INC_DIR)  # Fix the include path here

RM          = rm -f

SRC         = $(SRC_DIR)main.cpp \
			  $(SRC_DIR)text_area.cpp \
              $(SRC_DIR)button.cpp \
              $(SRC_DIR)pattern.cpp \
              $(SRC_DIR)saver.cpp \
              $(SRC_DIR)searcher.cpp \

OBJ         = $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(RAYLIB_LIB) $(CFLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp  # Correct this line from %.c to %.cpp to match your source files
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
