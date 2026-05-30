// Student Management System in C:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int rollNo;
    char name[50];
    float marks;
};

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void countStudents();
char getGrade(float marks);

int main()
{
    int choice;

    do
    {
        printf("\n========== STUDENT MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Count Students\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: countStudents(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while(choice != 7);

    return 0;
}

char getGrade(float marks)
{
    if(marks >= 90) return 'A';
    else if(marks >= 75) return 'B';
    else if(marks >= 60) return 'C';
    else if(marks >= 40) return 'D';
    else return 'F';
}

void addStudent()
{
    FILE *fp = fopen("students.dat", "ab+");
    struct Student s, temp;
    int duplicate = 0;

    if(fp == NULL)
    {
        printf("File error!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);

    rewind(fp);
    while(fread(&temp, sizeof(temp), 1, fp))
    {
        if(temp.rollNo == s.rollNo)
        {
            duplicate = 1;
            break;
        }
    }

    if(duplicate)
    {
        printf("Roll number already exists!\n");
        fclose(fp);
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Student added successfully.\n");
}

void displayStudents()
{
    FILE *fp = fopen("students.dat", "rb");
    struct Student s;

    if(fp == NULL)
    {
        printf("No records found.\n");
        return;
    }

    printf("\n%-10s %-25s %-10s %-10s\n",
           "Roll No", "Name", "Marks", "Grade");

    while(fread(&s, sizeof(s), 1, fp))
    {
        printf("%-10d %-25s %-10.2f %-10c\n",
               s.rollNo, s.name, s.marks, getGrade(s.marks));
    }

    fclose(fp);
}

void searchStudent()
{
    FILE *fp = fopen("students.dat", "rb");
    struct Student s;
    int roll, found = 0;

    if(fp == NULL)
    {
        printf("No records found.\n");
        return;
    }

    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    while(fread(&s, sizeof(s), 1, fp))
    {
        if(s.rollNo == roll)
        {
            printf("Student Found\n");
            printf("Roll No: %d\n", s.rollNo);
            printf("Name: %s\n", s.name);
            printf("Marks: %.2f\n", s.marks);
            printf("Grade: %c\n", getGrade(s.marks));
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Student not found.\n");

    fclose(fp);
}

void updateStudent()
{
    FILE *fp = fopen("students.dat", "rb+");
    struct Student s;
    int roll, found = 0;

    if(fp == NULL)
    {
        printf("No records found.\n");
        return;
    }

    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);

    while(fread(&s, sizeof(s), 1, fp))
    {
        if(s.rollNo == roll)
        {
            printf("Enter New Name: ");
            scanf(" %[^\n]", s.name);

            printf("Enter New Marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);

            found = 1;
            printf("Record updated successfully.\n");
            break;
        }
    }

    if(!found)
        printf("Student not found.\n");

    fclose(fp);
}

void deleteStudent()
{
    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Student s;
    int roll, found = 0;

    if(fp == NULL)
    {
        printf("No records found.\n");
        return;
    }

    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    while(fread(&s, sizeof(s), 1, fp))
    {
        if(s.rollNo == roll)
            found = 1;
        else
            fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if(found)
        printf("Record deleted successfully.\n");
    else
        printf("Student not found.\n");
}

void countStudents()
{
    FILE *fp = fopen("students.dat", "rb");
    struct Student s;
    int count = 0;

    if(fp == NULL)
    {
        printf("No records found.\n");
        return;
    }

    while(fread(&s, sizeof(s), 1, fp))
        count++;

    fclose(fp);

    printf("Total Students: %d\n", count);
}



