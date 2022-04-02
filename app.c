#include <stdio.h>
#include <windows.h>

/*function prototypes*/
void enterResults();
void getResults();
void rankStudents();
void printRank();

/*Defining properties for the studentDetails datatype*/
typedef struct{
    char name[2][20];//stores two names of maximum 20 characters
    int studentId;
    int marks[7];
    int average;

} studentDetails;

int numberOfStudents;
char courseUnits[7][50]={"Emerging Trends in Software Engineering","Communication Skills","Software Development Principles","Fundamentals of Software Engineering","Discrete Maths","Political Economy","introduction to C Programming"};

studentDetails fresherDetails[100];//maximum number of freshers is 100

int main(){
    system("COLOR F4");//changes color to f4
    start:
    system("cls");//clears screen
    printf("Enter an option:\n1.Enter Results\n2.Get Results\n3.Rank students\n");
    int option;
    scanf("%d",&option);
    system("cls");
    switch(option){
    case 1:
        enterResults();
        break;
    case 2:
        getResults();
        break;
    case 3:
        rankStudents();
        break;
    default:
        printf("Error in getOption Module.Invalid Argument!\n");
    }
    printf("Enter 1 to go back to menu or 0 to exit:\n");
    int entry;
    scanf("%d",&entry);
    if(entry==1)
    goto start;
    else if(entry==0){
    system("cls");
    system("COLOR 0F");
    }
    else
    printf("Error in entryModule.Invalid Argument.\n");
    return 0;

}
void enterResults(){
    printf("Results Entry Form:\n");
    printf("____________________________________________________________________________________________\n");
    printf("Enter the course:\n");
    char course[2][30];
    scanf("%s %s",&course[0],&course[1]);
    printf("Enter number of students:\n");
    scanf("%d",&numberOfStudents);

    /*Keep looping until the details for all students are entered*/

    int start=0;//starting point of our loop
    while(start<numberOfStudents){
        system("cls");
        printf("Results Entry Form:\t %s %s Class \t Student %d\n",course[0],course[1],start+1);

            printf("Enter name:\n");
            scanf("%s %s",&fresherDetails[start].name[0],&fresherDetails[start].name[1]);
            fresherDetails[start].studentId=start;
            int init=0;//starting point for the for loop
            printf("Enter marks for:");
            for(;init<7;init++){
                    printf("\n%s:\t",courseUnits[init]);
            scanf("%d",&fresherDetails[start].marks[init]);
            }

        start++;
    }


}
void getResults(){
    printf("Enter the student Id:\n");
    int id;
    scanf("%d",&id);
    system("cls");
    printf("RESULTS FORM:\n");
    printf("_______________________________________________________________________________________\n");
    printf("Name:\t%s %s \t \tStudent Id:%d\t\n",fresherDetails[id].name[0],fresherDetails[id].name[1],id);
    printf("Course Units\t\t\t\t Marks\t\n");
    int start=0;
    int sum=0;
    /*print a list of the courses with their marks*/
    while(start<7){
            printf("%s\t\t%d\t\n",courseUnits[start],fresherDetails[id].marks[start]);
        start++;
        sum+=fresherDetails[id].marks[start];
    }
    fresherDetails[id].average=sum/7;
    printf("Average:\t\t%d\n",fresherDetails[id].average);
}
void rankStudents(){
    int start=0,init=0;
    for(;start<numberOfStudents;start++){
            for(;init<numberOfStudents;init++){
                if(fresherDetails[init].average<fresherDetails[init+1].average){
                    studentDetails a=fresherDetails[init];
                    fresherDetails[init]=fresherDetails[init+1];
                    fresherDetails[init+1]=a;
                }

            }

    }
    printRank();

}
void printRank(){
    int start=0;
    printf("Student Report:\n");
    printf("_______________________________________________________________________________\n");
    printf("Position \t Student name\t\t\t Average\t\n");
    while(start<numberOfStudents){
        printf("%d\t\t%s %s \t %d\n",start+1,fresherDetails[start].name[0],fresherDetails[start].name[1],fresherDetails[start].average);
        start++;
    }
}
