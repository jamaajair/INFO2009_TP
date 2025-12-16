#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char matricule[8];
    struct student *next;
} student;

typedef struct {
    student *head;
    unsigned count;
} student_list;


int same_mat(const char a[8], const char b[8])
{
    unsigned i;
    for (i = 0; i < 8; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}


int add_student(student_list *l, const char m[8])
{
    student *p, *new;
    unsigned i;

    /* recherche du matricule */
    for (p = l->head; p; p = p->next) {
        if (same_mat(p->matricule, m))
            return -1;
    }

    /* allocation du nouvel étudiant */
    new = malloc(sizeof(student));
    if (!new)
        return -1;

    for (i = 0; i < 8; i++)
        new->matricule[i] = m[i];

    new->next = NULL;

    /* insertion en fin */
    if (!l->head) {
        l->head = new;
    } else {
        p = l->head;
        while (p->next)
            p = p->next;
        p->next = new;
    }

    l->count++;
    return 0;
}

void free_list(student_list *l)
{
    student *p, *next;

    p = l->head;
    while (p) {
        next = p->next;
        free(p);
        p = next;
    }

    l->head = NULL;
    l->count = 0;
}

int main(int argc, char const *argv[])
{
    student_list list = { NULL, 0 };
    add_student(&list, "A123456");
    add_student(&list, "B234567");
    // déja existe il ne faut pas l ajouter à la liste 
    add_student(&list, "A123456"); 
    printf("Number of students in the list: %u\n", list.count);
    free_list(&list);
    return 0;
}
