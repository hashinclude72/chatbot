#include "./res/chatbot.h"


const int t_k =150, t_f=50,t_c=50;
int h=0,ch,z=0;
char *sv,c[100],word[20][10],user_name[20],word_search[20][10],word_search2[20][10],
		keyword[150][20]={"sumit","vidyanand","shelly","shubhi","sachi","shahina","rohit","roohi","ravi","richa","prem","rajanikanth","poonam","parshant","nitika","pardeep","mitali","nelson","madam","malay","keshav","kingshuk","glen","hanumat","bhagwant","durgansh","amar","amber","adarsh","ajay","abhijit","manish","tripti","kalpana","deepa","monit","avita","apurva","shamik","amrendra","amit","ankit","tanmay","susheela","hitesh","varun","abhishek","ahatsham","amitava","harvinder","hey","thankyou","thanks","thank","hie","hiee","hiiee","wassup","fine","good","excellent","nothing","yes","no","upes","petroleum","cit","whats'up","hello","hy","hii","hi","name","namaste","heya","how","oss","osos","open","source","standards","ogi","oil","gas","ccvt","cloud","computing","cirtualization","mainframe","mft","e-commerce","ecom","e-com","commerce","it-infra","itinfra","infrastructure","business","analytics","optimization","bao",								"banking","financial","services","insurance","bfsi","cyber","security","forensics","csf","graphics","gaming","gg","internet","iot","mobile","application","development","ai","machine","learning","ml","devops","big","data","bigdata"},
		faculty[50][20]={"sumit","vidyanand","shelly","shubhi","sachi","shahina","rohit","roohi","ravi","richa","prem","rajanikanth","poonam","parshant","nitika","pardeep","mitali","nelson","madam","malay","keshav","kingshuk","glen","hanumat","bhagwant","durgansh","amar","amber","adarsh","ajay","abhijit","manish","tripti","kalpana","deepa","monit","avita","apurva","shamik","amrendra","amit","ankit","tanmay","susheela","hitesh","varun","abhishek","ahatsham","amitava","harvinder"},
		course[50][20]={"oss","osos","open","source","standards","ogi","oil","gas","ccvt","cloud","computing","virtualization","mainframe","mft","e-commerce","ecom","commerce","e-com","it-infra","itinfra","infrastructure","business","analytics","optimization","bao",								"banking","financial","services","insurance","bfsi","cyber","security","forensics","csf","graphics","gaming","gg","internet","iot","mobile","application","development","ai","machine","learning","ml","devops","big","data","bigdata"};

int print_words();
void search_faculty(char[]);
void search_course1(char[]);
void search_course2(char[]);
void search_subjects(char[]);
hashtable_t *htable;
hashtable_t *htable2;
hashtable_t *htable3;

int main() {
	htable = htable_create(60000);        //convo
	htable2 = htable_create(60000);      //cources
	htable3 = htable_create(60000);      //faculty

	FILE *f;
	f = fopen("./src/convo","r");

	char data[2][200];

	const int line_size = 200;
	char* take = malloc(line_size);

	while(!feof(f))
	{
		fgets(take, line_size, f);

		int q=0;
		sv = strtok(take,",");
		while( sv != NULL )
			{
			         strcpy(data[q],sv);
	 			 q++;
    	 			 sv = strtok(NULL,",");
			}
		htable_set(htable,data[0],data[1]);
	}
	fclose(f);


/////////////////
	f = fopen("./src/course_names","r");

	while(!feof(f))
	{
		fgets(take, line_size, f);

		int q=0;
		sv = strtok(take,",");
		while( sv != NULL )
			{
			         strcpy(data[q],sv);
	 			 q++;
    	 			 sv = strtok(NULL,",");
			}
		htable_set(htable2,data[0],data[1]);
	}
	fclose(f);

	f = fopen("./src/faculty_names","r");

	while(!feof(f))
	{
		fgets(take, line_size, f);

		int q=0;
		sv = strtok(take,",");
		while( sv != NULL )
			{
							 strcpy(data[q],sv);
				 q++;
						 sv = strtok(NULL,",");
			}
		htable_set(htable3,data[0],data[1]);
	}
	fclose(f);


  printf("What's your name? :- " );
	gets(user_name);
	printf("Hello %s, Nice to have you.\n",user_name);
	printf("Type your query....\n");


while (1) {
	// ++z;
	// printf("\nz - %d \n", z);
  h=0;
	printf(">>>");
	gets(c);
	strlwr(c);

  int l=0;
	sv = strtok(c," -,/.*");
	while( sv != NULL )
	{
	  strcpy(word[l],sv);
	  l++;
    	  sv = strtok(NULL," -,/.*");
	}
	int j=0,i=0;
	for(i=0;i<l;i++)
	{
		for(j=0;j<t_k;j++)
		{
			if(strcmp(word[i],keyword[j])==0)
			{
				strcpy(word_search[h++],word[i]);
				}

		}
	}

print_words();


}
		return 0;
}



void search_faculty(char name[10]){
	int i=0;
	for(i=0;i<t_f;i++){

	if (strcmp(name,faculty[i])==0) {

	char c;
	char addr[20]="./src/faculty/";
	strcat(addr,name);

	FILE *f = fopen(addr, "r");
	c = fgetc(f);
	while (c != EOF)
	{
			printf ("%c", c);
			c = fgetc(f);
	}
	fclose(f);

}
} free(name);
printf("\n");
}

void search_course1(char name[20]){
	int i=0;
	char course1[50][20]={"ccvt","cloud","computing","cirtualization","business","analytics","optimization","bao",	"cyber","security","forensics","csf"};
  for (i = 0; i < t_c; i++) {
		if (strcmp(name,course1[i])==0) {
			char c;
			char addr[20]="./src/course_set1";
			FILE *f = fopen(addr, "r");
			c = fgetc(f);
			while (c != EOF)
			{
					printf ("%c", c);
					c = fgetc(f);
			}
			fclose(f);
		}
	}
	printf("\n\n\n" );
}

void search_course2(char name[20]){
	int i=0;
	char course2[50][20]={"oss","osos","open","source","standards","ogi","oil","gas","cirtualization","mainframe","mft","e-commerce","ecom","commerce","e-com","it-infra","itinfra","infrastructure","banking","financial","services","insurance","bfsi","graphics","gaming","gg","internet","iot","mobile","application","development","ai","machine","learning","ml","devops","big","data","bigdata"};

	for (i = 0; i < t_c; i++) {
		if (strcmp(name,course2[i])==0) {
			char c;
			char addr[20]="./src/course_set2";
			FILE *f = fopen(addr, "r");
			c = fgetc(f);
			while (c != EOF)
			{
					printf ("%c", c);
					c = fgetc(f);
			}
			fclose(f);
		}
	}
	printf("\n\n\n" );
}

void search_subjects(char name[20]){

	int i=0;
	for(i=0;i<t_c;i++){

	if (strcmp(name,course[i])==0) {

	char c;
	char addr[30]="./src/branch_subjects/";
	strcat(addr,name);
  strcat(addr,".txt");
	FILE *f = fopen(addr, "r");
	c = fgetc(f);
	while (c != EOF)
	{
			printf ("%c", c);
			c = fgetc(f);
	}
	fclose(f);

}
}
printf("\n");
}

int print_words(){
	if(h==1){
		// printf("test4\n");
		int x;
		for(int i=0;i<t_c;i++){
			if(strcmp(word_search[0],course[i])==0){
				x=1;
			}
		}
		if(x==1){
			printf("\n Choose one option (1,2,3) :-  \n");
			printf("\n 1. Want financial details?  \n");
			printf("\n 2. Want sem subject details?  \n");
			printf("\n 3. Want both the details?  \n");
			printf(">>>");
			scanf("%d",&ch);
			if(ch==1){
				search_course1(word_search[0]);
				search_course2(word_search[0]);
				gets(c);
			}
			else if(ch==2){
				search_subjects(word_search[0]);
				gets(c);
			}
			else if(ch==3){
				printf("\n\n__________________________Subjects Details__________________________________________________________________\n\n");
				search_subjects(word_search[0]);
				printf("__________________________Finacitial Details__________________________________________________________________\n\n");
				search_course1(word_search[0]);
				search_course2(word_search[0]);
				gets(c);
			}
		}
		else{
  		search_faculty(word_search[0]);
  		puts(htable_get( htable, word_search[0]));
		}
		// h=0;
		// printf(">>>");
		// gets(c);
 }


  if(h==0){
 	 printf("\nplease be more specific.\n");
	 // h=0;
 	 }

 	 if (h>1) {
		 int i,j,k=0,flag=0,flag2=0,l;
		 printf("\n\n%s ,I found more than one keyword in your sentence. Please choose one (1....n):\n\n",user_name);
		 for (i = 0; i < h; i++) {
			 flag2=0;
			 	for (j = 0; j < t_c; j++) {
		 			if(strcmp(word_search[i],course[j])==0){
						flag2++;
						if(flag==0){
							strcpy(word_search2[k++],word_search[i]);
							printf("%d. ",k);
							l=k;
		 				 	puts(htable_get( htable2, word_search2[k-1]));
							// printf("test4\n");
							flag++;
			  		}
					}
		 		}
				if(flag2==0){
					// printf("test5\n");
					strcpy(word_search2[k++],word_search[i]);
					printf("%d. ",k);
					if(htable_get( htable3, word_search2[k-1])){
						puts(htable_get( htable3, word_search2[k-1]));
					}
					else{printf("%s\n\n",word_search2[k-1]);}
					// printf("%d. %s\n",k,word_search2[k-1]);
					// printf("test6\n");
					flag2++;
				}
	 		}



 		 // for (i=0;i<k;i++) {
			//  if(flag==1){
			// 	 printf("%d. ",i+1);
			// 	 puts(htable_get( htable2, word_search2[i]));
			// 	 flag++;
			//  	}
			//  else{
 			// 		printf("%d. %s\n",i+1,word_search2[i]);
			// 	}
 		 // }
     printf(">>>");
 		 scanf("%d",&ch);
 		 // printf("lkjhgff  ");
 		 int gh = ch-1;
		 if(l==ch){
			 printf("\n Choose one option (1,2,3) :-  \n");
			 printf("\n 1. Want financial details?  \n");
			 printf("\n 2. Want sem subject details?  \n");
			 printf("\n 3. Want both the details?  \n");
			 printf(">>>");
			 scanf("%d",&ch);
			 if(ch==1){
				 search_course1(word_search[gh]);
			 	 search_course2(word_search[gh]);
			 }
			 else if(ch==2){
				 search_subjects(word_search[gh]);
			 }
			 else if(ch==3){
				 printf("\n\n__________________________Subjects Details__________________________________________________________________\n\n");
				 search_subjects(word_search[gh]);
				 printf("\n\n__________________________Finacitial Details__________________________________________________________________\n\n");
				 search_course1(word_search[gh]);
			 	 search_course2(word_search[gh]);
			 }

		 }
		 else{
 		 		search_faculty(word_search2[gh]);
 		 		puts(htable_get( htable, word_search2[gh]));
	 		}
		 gets(c);
		 // h=0;
 	 }
}
