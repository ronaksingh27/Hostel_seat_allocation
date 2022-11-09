//initial delcarations start//
#define DB_SIZE 1500
#define  NAME_LEN 100
#define DEPT_LEN 10
#define RES_LEN 20
#define HOS_LEN 30
#define N 1500
#define ROWS 100
#define COLS 100
#include<stdio.h>
#include <string.h>
//________________________________________________________________


//struct def starts
struct room_partner{
    char name[NAME_LEN];
    int  year;
    char department[DEPT_LEN];
};

struct student_record{
    char name[NAME_LEN];
    int  year;
    int serial_no;
    char department[DEPT_LEN];
    char prev_hostel_alloted[HOS_LEN];
    char pref_hostel[HOS_LEN];
    char hostel_alloted[HOS_LEN];
    int pref_floor;
    int alloted_floor;
    int alloted_room_no;
    char partner_alloted[NAME_LEN];
    int first_pref;
    int second_pref;
    struct room_partner pref_partner;
};
//________________________________________________________________




//QB Solution
//________________________________________________________________
//----------------------------------------------------------------
//used when one prefers over another
int s1Preferss3Overs2(int stable[ROWS][COLS], int s1, int s2, int s3)
{
    for (int i = 0; i < N; i++)
    {
        if (stable[s1][i] == s3)
            return 1;
        if (stable[s1][i] == s2)
           return 0;
    }
}
//________________________________________________________________

//stable combiantion solve dusing stable marriage intutition
int stable_combination(int stable[ROWS][COLS],int size,struct student_record student_info[]){
    int flag=1;
    int count=0;
    int sPartner[size];
    int s2Free[size];
    int freeCount = size;
  
    while (freeCount > 0)
    {
        int s2;
        for (s2 = 0; s2 < size && flag==1; s2++)
            if (s2Free[s2] == 0)
                flag==0;
        for (int i = 0; i < size && s2Free[s2] == 0; i++)
        {
            int s1 = stable[s2][i];
            if (sPartner[s1-size] == -1)
            {
                sPartner[s1-size] = s2;
                s2Free[s2] = 1;
                freeCount--;
            }
  
            else  
            {
                int s3 = sPartner[s1-size];
  
                if (s1Preferss3Overs2(stable, s1, s2, s3) == 0)
                {
                    sPartner[s1-size] = s2;
                    s2Free[s2] = 1;
                    s2Free[s3] = 0;
                }
            } 
        } 
    } 
  
      return 1;
}
//________________________________________________________________


//store preferences for sub_question B 
int store_preference_1(int i,int j,struct student_record student_info[]){
    int res_1 = strcmp(student_info[i].department,student_info[j].department);
    int res_2 = student_info[i].year - student_info[j].year;
    if(res_1==0 && res_2==0 && i!=j){
        return student_info[j].serial_no;
    }
    else return 0;
}

int store_preference_2(int i,int j,struct student_record student_info[]){
    int res_1 = strcmp(student_info[i].department,student_info[j].department);
    int res_2 = student_info[i].year - student_info[j].year;
    if(res_1!=0 && res_2==0 && i!=j){
        return student_info[j].serial_no;
    }
    else return 0;
}

int store_preference_3(int i,int j,struct student_record student_info[]){
    int res_1 = strcmp(student_info[i].department,student_info[j].department);
    int res_2 = student_info[i].year - student_info[j].year;
    if(res_2<0 && i!=j){
        return student_info[j].serial_no;
    }
    else return 0;
}

int store_preference_4(int i,int j,struct student_record student_info[]){
    int res_1 = strcmp(student_info[i].department,student_info[j].department);
    int res_2 = student_info[i].year - student_info[j].year;
    if(res_1==0 && res_2>0 && i!=j){
        return student_info[j].serial_no;
    }
    else return 0;
}

int store_preference_5(int i,int j,struct student_record student_info[]){
    int res_1 = strcmp(student_info[i].department,student_info[j].department);
    int res_2 = student_info[i].year - student_info[j].year;
    if(res_1!=0 && res_2>0 && i!=j){
        return student_info[j].serial_no;
    }
    else return 0;
}
//________________________________________________________________

//counting of no of students as per preferences
int count_pref_one(int i,int size,struct student_record student_info[]){
    int j,count=0;
    
    for(j=0;j<size;j++){
        int res_1 = strcmp(student_info[i].department,student_info[j].department);
        int res_2 = student_info[i].year - student_info[j].year;
        if(res_1==0 && res_2==0 && i!=j){
            count++;
        }
    }
    
    return count;
}

int count_pref_two(int i,int size,struct student_record student_info[]){
    int j,count=0;
    
    for(j=0;j<size;j++){
        int res_1 = strcmp(student_info[i].department,student_info[j].department);
        int res_2 = student_info[i].year - student_info[j].year;
        if(res_1!=0 && res_2==0 && i!=j){
            count++;
        }
    }
    
    return count;
}

int count_pref_three(int i,int size,struct student_record student_info[]){
    int j,count=0;
    for(j=0;j<size;j++){
         int res_1 = strcmp(student_info[i].department,student_info[j].department);
        int res_2 = student_info[i].year - student_info[j].year;
        if(res_2<0 && i!=j){
            count++;
        }
    }
    
    return count;
}

int count_pref_four(int i,int size,struct student_record student_info[]){
    int j,count=0;
   
    for(j=0;j<size;j++){
        int res_1 = strcmp(student_info[i].department,student_info[j].department);
        int res_2 = student_info[i].year - student_info[j].year;
        if(res_1==0 && res_2>0 && i!=j){
            count++;
        }
    }
    
    return count;
}


int count_pref_five(int i,int size,struct student_record student_info[]){
    int j,count=0;
   
    for(j=0;j<size;j++){
        int res_1 = strcmp(student_info[i].department,student_info[j].department);
        int res_2 = student_info[i].year - student_info[j].year;
        if(res_1!=0 && res_2>0 && i!=j){
            count++;
        }
    }
    
    return count;
}
//________________________________________________________________________________________________________________________________


//arranging the preferneces in a 2D array for Gale Shapley algo
int stable_combination_input(int stable[ROWS][COLS],int size,struct student_record student_info[]){
    int i,j,count=0;
    int stable_updated[size][size-1];
    
    
    for( i=0;i<size;i++){
        stable[i][0]=i;
    }
    
    for(i=0;i<size;i++){
        int k=1;
        int count_pref_1 = count_pref_one(i,size,student_info);
        int count_pref_2 = count_pref_two(i,size,student_info);
        int count_pref_3 = count_pref_three(i,size,student_info);
        int count_pref_4 = count_pref_four(i,size,student_info);
        int count_pref_5 = count_pref_five(i,size,student_info);
        for(j=1;j<size;i++){
            
            while(count_pref_1>0){
                stable[i][k]=store_preference_1(i,j,student_info);
                k++;
                count_pref_1--;
            }
            while(count_pref_2>0){
                stable[i][k]=store_preference_2(i,j,student_info);
                k++;
                count_pref_2--;
            }
            while(count_pref_3>0){
                stable[i][k]=store_preference_3(i,j,student_info);
                k++;
                count_pref_3--;
            }
            while(count_pref_4>0){
                stable[i][k]=store_preference_4(i,j,student_info);
                k++;
                count_pref_4--;
            }
            while(count_pref_5>0){
                stable[i][k]=store_preference_5(i,j,student_info);
                k++;
                count_pref_5--;
            }
            
        }
    }
    
    for(i=0;i<size;i++){
        for(j=0;j<size-1;j++){
            stable_updated[i][j] = stable[i][j+1];
        }
    }
    
    //taking all the permutations of the rows(prefernces in order) wrt to each other and then applying Gale Shapley 
    //stable marriage problem intuition on the half - half rows and then calculating the stable combinations
    
    
    if(stable_combination(stable_updated,size,student_info)==1) count++;
    
    //count by size/2  because for each half the I half will be have as identical when permutation is done
    return count/(size/2);
    
}
//________________________________________________________________
//----------------------------------------------------------------






//QA Solution
//________________________________________________________________
//----------------------------------------------------------------
// print room partner
void print_roompartner(struct student_record student_info[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("----------------------------------------------------------------------------------\n");
        printf("Name of student : %s \n",student_info[i].name);
        printf("The partner alloted is %s \n",student_info[i].partner_alloted);
    }
}
//________________________________________________________________



//intitalsiing student database
void initialize_stud_DB(struct student_record stud_info[],int size){
    int i;
    for(i=0;i<size;i++){
        stud_info[i].name[0]='\0';
        stud_info[i].year=0;
        stud_info[i].serial_no=0;
        stud_info[i].department[0]='\0';
        stud_info[i].prev_hostel_alloted[0]='\0';
        stud_info[i].pref_hostel[0]='\0';
        stud_info[i].hostel_alloted[0]='\0';
        stud_info[i].pref_floor=0;
        stud_info[i].alloted_floor=0;
        stud_info[i].alloted_room_no=0;
        stud_info[i].partner_alloted[0]='\0';
        stud_info[i].pref_partner.name[0]='\0';
        stud_info[i].pref_partner.department[0]='\0';
        stud_info[i].pref_partner.year=0;
        stud_info[i].first_pref=0;
        stud_info[i].second_pref=0;
    }
}
//________________________________________________________________


//add student to the database
void add_student(struct student_record student_info[],int num_rec){
    int year,i,pref_floor,pref_partner_year,pref_partner_roll_no;
    char name[NAME_LEN],department[DEPT_LEN],pref_hostel[HOS_LEN],hostel_alloted[HOS_LEN],pref_partner_name[NAME_LEN],pref_partner_department[DEPT_LEN],prev_hostel_alloted[HOS_LEN];

    
    for(i=0;i<num_rec;i++){
         printf("Enter name:");
          scanf("%s",name);
          printf("Enter year:");
          scanf("%d",&year);
          printf("Enter department :");
          scanf("%s",department);
          printf("preferred hostel : ");
          scanf("%s",pref_hostel);
          printf("hostel_alloted : ");
          scanf("%s",hostel_alloted);
          if(year>1){
            printf("previous hostel_alloted : ");
            scanf("%s",prev_hostel_alloted);
            printf("preferred floor :");
            scanf("%d",&pref_floor);
            printf("preferred partner name :");
            scanf("%s",pref_partner_name);
            printf("preferred partner department :");
            scanf("%s",pref_partner_department);
            printf("preferred partner year :");
            scanf("%d",&pref_partner_year);

        student_info[i].pref_floor = pref_floor;
          strcpy(student_info[i].prev_hostel_alloted,prev_hostel_alloted);
          strcpy(student_info[i].pref_partner.name,pref_partner_name);
          strcpy(student_info[i].pref_partner.department,pref_partner_department);
          student_info[i].pref_partner.year= pref_partner_year;
          }
         
         printf("----------------------------------------------------------------------------------\n");
          
          
          strcpy(student_info[i].name,name);
          student_info[i].year=year;
          strcpy(student_info[i].department,department);
          strcpy(student_info[i].pref_hostel,pref_hostel);
          student_info[i].serial_no=i;
          strcpy(student_info[i].hostel_alloted,hostel_alloted);
          
    }

}
//________________________________________________________________




void count_first_pref(struct student_record student_info[],int size){
    int i,count=0;;
    for(i=0;i<size;i++){
        if(student_info[i].first_pref==1) count++;
    }
     printf("No of student who got rooms as their first prefernce is %d \n ",count);
}
    
void count_second_pref(struct student_record student_info[],int size){
    int i,count=0;;
    for(i=0;i<size;i++){
        if(student_info[i].second_pref==1) count++;
    }
    printf("No of student who got rooms as their second prefernce is %d \n ",count);
}

//counting second preference of student
void seat_second_prefernece(struct student_record student_info[],int hostel_info[],int hostel_roomstu[] ,int size){
    int i,j;

    // i is hunting j as room partner
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            int result_1 = strcmp(student_info[i].pref_partner.name,student_info[j].name);
            int result_2 = strcmp(student_info[j].pref_partner.name,student_info[i].name);
            if( student_info[i].year>1 && student_info[j].year>1 && result_1==0 && result_2==0 ){

                int choice = student_info[j].alloted_floor;
                switch(choice){
                    case 1:
                    {
                        if(hostel_roomstu[1]>=1){
                            hostel_roomstu[1]--;
                            student_info[i].second_pref=1;
                        }
                    }
                    break;
                    case 2:
                    {
                        if(hostel_roomstu[2]>=1){
                            hostel_roomstu[2]--;
                            student_info[i].second_pref=1;
                        }
                    }
                    break;
                    case 3:
                    {
                        if(hostel_roomstu[3]>=1){
                            hostel_roomstu[3]--;
                            student_info[i].second_pref=1;
                        }
                    }
                    break;

                    default:
                    printf("Hostel room not alloted");
                }
                
            }
        }
    }
}
//________________________________________________________________


//counting first prefernce of student
void seat_first_preference(struct student_record student_info[],int hostel_info[] ,int hostel_roomstu[],int size,int i){

                    if(student_info[i].pref_floor == 1){
                        if(hostel_roomstu[1]>=1){
                            hostel_roomstu[1]--;
                            student_info[i].alloted_floor=1;
                            student_info[i].first_pref=1;
                            //strcpy(student_info[i].hostel_alloted,student_info[i].pref_hostel);
                        }
                        else {
                            seat_second_prefernece(student_info,hostel_info,hostel_roomstu,size);
                        }
                       
                    }
                    else if(student_info[i].pref_floor == 2){
                        if(hostel_roomstu[2]>=1){
                            hostel_roomstu[2]--;
                            student_info[i].alloted_floor=2;
                            strcpy(student_info[i].hostel_alloted,student_info[i].pref_hostel);
                            student_info[i].first_pref=1;
                        }
                         else {
                            seat_second_prefernece(student_info,hostel_info,hostel_roomstu,size);
                        }
                    }
                    else if(student_info[i].pref_floor == 3){
                        if(hostel_roomstu[3]>=1){
                            hostel_roomstu[3]--;
                            student_info[i].alloted_floor=3;
                            strcpy(student_info[i].hostel_alloted,student_info[i].pref_hostel);
                            student_info[i].first_pref=1;
                        }
                        else{
                            seat_second_prefernece(student_info,hostel_info,hostel_roomstu,size);
                        }
                    }
}
//________________________________________________________________


//hostel seat allotment function
void seat_allotment(struct student_record student_info[],int hostel_info[],int hostel_roomstu[],int size){
    int i,choice;
    char hostel_name[]="hb2";
    char outside[HOS_LEN] = "hostel_outside";
    int result_1 = strcmp(student_info[i].prev_hostel_alloted,student_info[i].pref_hostel);
    int result_2 = strcmp(student_info[i].prev_hostel_alloted,outside);


    //seats ffirst alloted to first yar only
    for(i=0;i<size;i++)
    {
        if(student_info[i].year==1)
        {
            if(hostel_roomstu[0]>=1){
                    hostel_roomstu[0] =  hostel_roomstu[0] - 1;
                    strcpy(student_info[i].hostel_alloted,hostel_name);
                    student_info[i].alloted_floor = 0;
                }
        }
    }
    for(i=0;i<size;i++)
    {
        if(result_1==0&&student_info[i].year>1)
        {
            seat_first_preference(student_info,hostel_info,hostel_roomstu,size,i);
        }
    }
    for(i=0;i<size;i++)
    {
        if(result_2==0&&student_info[i].year>1)
        {
            seat_first_preference(student_info,hostel_info,hostel_roomstu,size,i);
        }
    }
    for(i=0;i<size;i++)
    {
        if(result_1!=0&&result_2!=0&&student_info[i].year>1)
        {
            seat_first_preference(student_info,hostel_info,hostel_roomstu,size,i);
        }
    }
}
//________________________________________________________________



//print student info 
void print_student_info(struct student_record student_info[],int num_rec){
    int i;
    for(i=0;i<num_rec;i++){
        
        printf("----------------------------------------------------------------------------------\n");
        printf("Name of student : %s \n",student_info[i].name);
        printf("Year of student : %d \n",student_info[i].year);
        printf("Dept of student : %s \n",student_info[i].department);
        printf("Preferred hostel : %s \n\n",student_info[i].pref_hostel);
        // printf("hostel alloted : %s \n",student_info[i].hostel_alloted);
        if(student_info[i].year >1){
            printf("previous alloted hostel : %s \n",student_info[i].prev_hostel_alloted);
            printf("Preferred floor : %d \n",student_info[i].pref_floor);
            printf("preferred partner name : %s \n",student_info[i].pref_partner.name);
            printf("Preferred partner department : %s \n",student_info[i].pref_partner.department);
            printf("preferred partner year : %d \n",student_info[i].pref_partner.year);
            // printf("preferred partner roll no : %d \n\n",student_info[i].pref_partner.roll_no);
            printf("alloted floor : %d \n",student_info[i].alloted_floor);
            printf("First pref ->  %d \n",student_info[i].first_pref);
            printf("Second pref ->  %d \n",student_info[i].second_pref);
        };
    }
}
//________________________________________________________________
//----------------------------------------------------------------



//QC Solution
//________________________________________________________________
//----------------------------------------------------------------
//print all possible allotments as per preferences mentioned in subQ.B for subQ.C
void all_possible_allotments(struct student_record student_info[],int hostel_info[],int hostel_roomstu[],int size){

    int i,student_id = 10;
    int res_1= strcmp(student_info[i].department,student_info[student_id].department);
    for(i=0;i<size;i++){
        if(res_1==0 && student_info[i].year==student_info[student_id].year){
            printf(" %s  &  %s  have same department and same year",student_info[i].name,student_info[student_id].name);
        };
    }

    for(i=0;i<size;i++){
        if(res_1!=0 && student_info[i].year==student_info[student_id].year){
            printf(" %s  &  %s  have different department but same year",student_info[i].name,student_info[student_id].name);
        };
    }

    for(i=0;i<size;i++){
        if(res_1!=0 && student_info[i].year<student_info[student_id].year){
            printf(" %s is junior of %s",student_info[i].name,student_info[student_id].name);
        };
    }

    for(i=0;i<size;i++){
        if(res_1==0 && student_info[i].year>student_info[student_id].year){
            printf(" %s is senior of %s with same department",student_info[i].name,student_info[student_id].name);
        };
    }

    for(i=0;i<size;i++){
        if(res_1!=0 && student_info[i].year>student_info[student_id].year){
            printf(" %s is senior of %s with other department",student_info[i].name,student_info[student_id].name);
        };
    }
}
//________________________________________________________________
//----------------------------------------------------------------





//main function
int main(){
    
     struct student_record student_info[DB_SIZE];
     int hostel_info[4];
     int hostel_roomstu[4];
     int n,i,j,num_rec;

     initialize_stud_DB(student_info,DB_SIZE);

    
    printf("Enter the total no of rooms available in your hostel -> ");
    scanf("%d",&n);
    hostel_info[0] = n/4 -2;
    hostel_info[1] = n/4;
    hostel_info[2] = n/4;
    hostel_info[3] = n/4;
    hostel_roomstu[0] = n/2 -4;
    hostel_roomstu[1] = n/2;
    hostel_roomstu[2] = n/2;
    hostel_roomstu[3] = n/2;
    

    printf("Enter the no of records you want to insert: ");
    scanf("%d",&num_rec);
     printf("----------------------------------------------------------------------------------\n");
    add_student(student_info,num_rec);

    seat_allotment(student_info,hostel_info,hostel_roomstu,num_rec);
    //No of seats filled in each floor
    printf("The number of seats filled in ground floor is %d\n",n/2-4-hostel_roomstu[0]);
    printf("The number of seats filled in 1st floor is %d\n",n/2-hostel_roomstu[1]);
    printf("The number of seats filled in 2nd floor is %d\n",n/2-hostel_roomstu[2]);
    printf("The number of seats filled in 3rd floor is %d\n",n/2-hostel_roomstu[3]);

    //No of vacant seats filled in each floor
    printf("The number of vacant seats in ground floor is %d\n",hostel_roomstu[0]);
    printf("The number of vacant seats in 1st floor is %d\n",hostel_roomstu[1]);
    printf("The number of vacant seats in 2nd floor is %d\n",hostel_roomstu[2]);
    printf("The number of vacant seats in 3rd floor is %d\n",hostel_roomstu[3]);

    // print_seats_filled(hostel_info,n);
    
    // print_vacant_seats(hostel_info);
    count_first_pref(student_info,num_rec);
    count_second_pref(student_info,num_rec);
    
    
    // int p=stable_combination(student_info,hostel_info,hostel_roomstu,num_rec);
    // printf("the total number of stable combination are %d\n",p);

    print_student_info(student_info,num_rec);
    print_roompartner(student_info,num_rec);
    
    int stable[num_rec][num_rec];
    
    
    
    all_possible_allotments(student_info,hostel_info,hostel_roomstu,num_rec);
    
    int p = stable_combination_input(stable,num_rec,student_info);
    
    printf("total no of stable combinations is : %d",p);
}
//________________________________________________________________
//----------------------------------------------------------------

/*
HOSTEL MANAGEMENT SYSTEM -> batch R2
Prof-> Dr.Ravindra Keksar
project completed by RONAK_SINGH BT21CSE028 VNIT_25_BATCH && RAJAS_CHAVHAN BT21CSE031 VNIT_25_BATCH
The project demanded knowledge of struct and its implementation, knowledge of algorithms by economists,
here it was Gale-Shapley Algorithm.It tested our problem solving and concept/intution implementation competency.
 */