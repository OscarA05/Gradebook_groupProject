all:
	gcc -std=c11 -Wall -Wextra -Werror main.c gradebook.c savinginfo.c student_features.c -o gradebook

run:
	./gradebook

clean:
	rm -f gradebook

test:
	./gradebook < records.txt
