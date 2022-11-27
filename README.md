# Get_Next_Line
Getnextline

Third project in Hive Helsinki

Task is to get text out of given file descriptor.
This project introduces static variables, buffers and how
memory allocation operates in different parts(heap, stack).

Major issue for me was definetely memory leaks. Gladly
there was people who were way smarter than me and
helped and explained how allocations and freeing works.

Usage:

1. Clone the repository
```
git clone https://github.com/MiikaViini/Get_Next_Line.git
```
2. Compile library
```
make -C libft/
```
then make objects
```
clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
```
then compile with main.c
```
clang main.o get_next_line.o -I libft/includes -L libft/ -lft
```
3. Run
```
./a.out
```

