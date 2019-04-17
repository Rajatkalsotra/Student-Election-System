//CREATED BY RAJAT AND ROHIT.MAIN
//election polls system
//fp2 = voters.txt,fp1 = candidates.txt,fp3 = number.txt
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char heading()//HEADING
{
    system("cls");

	printf("\n\t\t    SIR M VISVESVARAYA INSTITUTE OF TECHNOLOGY\n");
	printf("------------------------------------------------------------------------------------\n\n");
	printf("\t\t  WELCOME TO THE SMVIT STUDENT PRESIDENT ELECTION\n\n");
	printf("\t\t\t   **************************\n");
	printf("\n\n\n");
}

int main()
{
	//VARIABLE DECLARATION
	FILE *fp2,*fp1,*fp3;
	int num=0,year,ch,n=0,res,a[50],i,go,m=1,no,len, j;
	char name1[80],branch[20],cand[20],name2[80],voter[80],che[20],c;

	system("cls");

	heading();
	fflush(stdin);
	//USER ENTRY
	printf("\n\n\t\t\t  ENTER NAME:");
    gets(name1);
    //Removing spaces in name
	len=strlen(name1);
	for(i=0; i<len; i++)
	{
		if(name1[i]==' ')
		{
			for(j=i; j<len; j++)
			{
				name1[j]=name1[j+1];
			}
		len--;
		}
	}

    printf("\t\t\t  ENTER YEAR:");
	scanf("%d",&year);
	printf("\t\t\t  ENTER BRANCH:");
	scanf("%s",branch);

	fp2 = fopen("voters.txt","r");
	while(fscanf(fp2,"%s",name2)!= EOF)
    {
       if(stricmp(name1,name2)==0)
        {
            printf("You have already voted.\n");
            exit(0);
        }

    }

		fclose(fp2);
		fp2 = fopen("voters.txt","a");
		fprintf(fp2,"%s\n",name1);

		fclose(fp2);

		printf("**************\n");

		system("cls");

		heading();
		printf("Rule Book:\n\n");
		printf("1.You can vote only once.\n2.Enter names as per registered in college.\n3.You can add new candidates but those must be from 4th year.");
		printf("\n4.Student from any branch can participate.\n5.Please be fair and impartial in voting.\n");
		printf("\n\n\n\n\n\n\n\nEnter 1 to continue:");
		scanf("%d",&no);
		if(no==1)
			{
				system("cls");
				goto go;
			}


		go :
			system("cls");
			fflush(stdin);
			heading();
			printf("\n\nWELCOME :  %s\n\n",name1);
			printf("1.For voting\n2.Add candidate\n3.List of voters\n4.Live count\n5.List of Candidates\n6.Exit\n");
			printf("\n\n\nEnter Response: ");
			scanf("%d",&ch);
			system("cls");
			fp1=fopen("candidates.txt","r");
			for(c=getc(fp1);c!=EOF;c=getc(fp1))//for finding no of candidates
				if(c == '\n')
					n = n + 1;
            fclose(fp1);

		if(ch==1)
		{
			system("cls");
			heading();
			printf("\n LIST OF CONTESTING CANDIDATES:\n\n");
			fp1 = fopen("candidates.txt","r");
			for(i=0;i<n;i++)
			{
				if(fgets(cand,20,fp1)>0)
                {   printf("%d.%s",m,cand);
					m=m+1;
                }
			}
			fclose(fp1);
			m=1;
			fp3 = fopen("number.txt","r");

			for(i=0;i<n;i++)
			{
				fscanf(fp3,"%d",&a[i]);
			}
			printf("\n\nEnter Your Response:");
			scanf("%d",&res);
			i = res-1;
			a[i] = a[i] + 1;
			fclose(fp3);

			fp3 = fopen("number.txt","w");
			for(i=0;i<n;i++)
				{
				fprintf(fp3,"%d\n",a[i]);
				}
			fclose(fp3);
			printf("\nYour response has been submitted succesfully\n");

            heading();
            m=1;
            fp3 = fopen("number.txt","r");
            fp1 = fopen("candidates.txt","r");
           printf("\n\nS.no\t\tNo of votes\t\tCandidate\n");
		printf("__________________________________________________\n");
		for(;;)
		{
			if(fgets(cand,20,fp1)>0)
			{
				if(fscanf(fp3,"%d",&num)>0)
				{
					printf("%d.\t\t %d \t\t\t%s",m,num,cand );
					m=m+1;
				}
				else break;
			}
			else break;
		}
            m=1;
            fclose(fp1);
            fclose(fp3);

		}

	else if(ch==2)
	{
		system("cls");
		heading();
        fflush(stdin);
		printf("Enter the name of new Candidate:\n");
        gets(cand);
		fp1 = fopen("candidates.txt","a");
		fprintf(fp1,"%s\n",cand);
		fclose(fp1);
		printf("Name is registered succesfully\n");
		goto go;

	}

	else if(ch==3)
	{
		system("cls");
		heading();

		fp2=fopen("voters.txt","r");
		m=1;
		for(i=0;i<1000;i++)
		{

			if(fgets(voter,20,fp2)>0)
			{
				printf("%d.%s",m,voter);
				m=m+1;
			}
		}
		m=1;
		fclose(fp2);
		printf("\n\nEnter 1 to return back to menu:");
		scanf("%d",&no);
		if(no==1)
			goto go;
	}

	else if(ch==4)
	{
		system("cls");
		fflush(stdin);
		heading();
		fp3 = fopen("number.txt","r");
		fp1 = fopen("candidates.txt","r");
		m=1;
		printf("\n\nS.no\t\tNo of votes\t\tCandidate\n");
		printf("__________________________________________________\n");
		for(;;)
		{
			if(fgets(cand,20,fp1)>0)
			{
				if(fscanf(fp3,"%d",&num)>0)
				{
					printf("%d.\t\t %d \t\t\t%s",m,num,cand );
					m=m+1;
				}
				else break;
			}
			else break;
		}
		m=1;
		fclose(fp1);
		fclose(fp3);
		printf("\n\nEnter 1 to return back to menu:");
		scanf("%d",&no);
		if(no==1)
			goto go;
	}
	else if(ch==5)
	{
		system("cls");
			heading();

			printf("\n LIST OF CONTESTING CANDIDATES:\n\n");
			fp1 = fopen("candidates.txt","r");
			for(i=0;i<n;i++)
			{
				if(fgets(cand,20,fp1)>0)
                {   printf("%d.%s",m,cand);
					m=m+1;
                }
			}
		m=1;
		printf("\n\nEnter 1 to return back to menu:");
		scanf("%d",&no);
		if(no==1)
			goto go;
	}
	else
        heading();
		printf("\n\n\t\t\t   *******THANK YOU*******\n");
		exit(0);
}
