#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void accountcreate();
void accountmaint();
void menu();
int main();
char read [50][50];
char read1 [50][50];
char read2 [50][50];
int num=0;
char aclvl;
void gotoxy(int x, int y)
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void superv()
{
	gotoxy(16,40); printf("SUPERVISOR");
}
void tell()
{
	gotoxy(16,40); printf("TELLER");
}
//iii
void designs()
{
	system("color 0B"); 
	 
	int width=167;
	int i; char c=219; int des=41;  
	gotoxy(0,0); 		//point of reference (x,y)
	time_t currentTime;
	time(&currentTime);
	
	struct tm *myTime=localtime(&currentTime);
	
	
	for( i=0;i<width;i++)
	{
		printf("%c",c);
	}
	
	gotoxy(0,42);		//bottom line border
	for(i=0;i<width;i++)
	{		printf("%c",c);
	}
	c=219;
	for(i=0;i<42;i++)	//left border 
	{
	gotoxy(0,des-i);
	printf("%c",c);	
	
	gotoxy(des,des-i);
	printf("%c",c);
	}
	for(int i=0;i<12;i++)		//G LETTER
	{
		if(i%2==0){
			gotoxy(3+i,3);printf("%c",254);
			gotoxy(3+i,10);printf("%c",254);
			gotoxy(27+i,3);printf("%c",254);
			gotoxy(27+i,10);printf("%c",254);
		}
		else
		{
		gotoxy(3+i,3);printf("%c",237);
		gotoxy(3+i,10);printf("%c",237);
		gotoxy(27+i,3);printf("%c",237);
		gotoxy(27+i,10);printf("%c",237);	
		}
	}
	for(i=0;i<9;i++)		//G LETTER center line	
	{
		if(i%2==0)
		{
			gotoxy(6+i,7); printf("%c",254);
			gotoxy(30+i,7); printf("%c",254);
		}
		else{
			gotoxy(6+i,7);printf("%c",237);
			gotoxy(30+i,7); printf("%c",237);
		}
	}
		gotoxy(14,8); printf("%c",254); gotoxy(14,9); printf("%c",254); gotoxy(38,8); printf("%c",254); gotoxy(38,9); printf("%c",254);
	for(i=0;i<6;i++)
	{
		gotoxy(18+i,7); printf("%c",219); //DASH LINE
	} gotoxy(19,10); printf("BANK"); gotoxy(10,13); printf("WELCOME TO G-G BANK!!!");
		
	for(int i=0;i<8;i++) // G Letter 
	{
		gotoxy(3,3+i);printf("%c",254);
		gotoxy(27,3+i); printf("%c",254);
	}
	for(i=0;i<40;i++) // cross border
	{
		gotoxy(1+i,12); printf("%c",219);
	}
	for(i=0;i<40;i++) //crossborder
	{
		gotoxy(1+i,39); printf("%c",219);
	}
	gotoxy(3,41);printf("DATE:  %i/%i/%i",myTime->tm_mon+1,myTime->tm_mday,myTime->tm_year+1900);
	gotoxy(3,40); printf("ACCESS LEVEL:"); 

}
//----
struct banking
{
	
	int recodnum;
	char accnum[50];
	char accname[50];
	float availbal;
	
	float deposit;
	float withdraw;
	float new_availbal;
}record[50];
void accountcreate()
{
	system("cls");
	char c;
	int i=0;
	c='y';
	while(c=='y'||c=='Y')
	{
	system("cls"); designs(); superv(); gotoxy(10,15); printf("~ACCOUNT CREATION~");
	gotoxy(5,16); printf("Enter Record Number: ");
	scanf("%d",&record[i].recodnum);
	gotoxy(5,17);printf("Enter Account Number: ");
	scanf("%s", record[i].accnum);
	gotoxy(5,18); printf("Enter Account Name: ");
	scanf("%s", record[i].accname);
	gotoxy(5,19); printf("Enter Balance: ");
	scanf("%f",&record[i].availbal);
	gotoxy(45,2); printf("~~~ACCOUNT DETAILS~~~");
	gotoxy(45,3); printf("Record Number:%d",record[i].recodnum);
	gotoxy(45,4); printf("Account Number:%s",record[i].accnum);
	gotoxy(45,5); printf("Account Name:%s",record[i].accname);
	gotoxy(45,6); printf("Available Balance:%.2f",record[i].availbal);
	FILE *fp;
	fp = fopen("listOfCustomers.txt", "a");
	fprintf(fp ,"%5d            %05s         %20s            %20.2f\n", record[i].recodnum, record[i].accnum, record[i].accname, record[i].availbal);
	fclose(fp);
	gotoxy(5,20); printf("Data is added successfulyy!");
	i++;
	num++;
	gotoxy(5,21); printf("Add record again? (Y/N)");
	gotoxy(5,22); printf("Enter your choice: ");
	scanf(" %c", &c);
	}
	if(c!='y'||c!='Y')
	{
		
		gotoxy(5,23); printf("Exiting.....\n");
		Sleep(500);
		main();
	}
		
}

void accountmaint()
{
	char edit[50];
	int i;
	char c;
	c='y';
	while(c=='y'||c=='Y')
	{
	system("cls"); designs(); superv();	gotoxy(5,15); printf("~ACCOUNT MAINTENANCE~");
	gotoxy(5,16);	printf("Enter account number"); 
	gotoxy(5,17);	printf("Enter your choice:");
	
	scanf("%s",edit);
	
	
	for(i=0;i<num;i++)
	{
		if(strcmp(edit,record[i].accnum)==0)
		{	gotoxy(45,2); printf("~~~ACCOUNT DETAILS~~~");
			gotoxy(45,3); printf("Old account");
			gotoxy(45,4); printf("No.");gotoxy(49,4); printf("AccountNo.");	
			gotoxy(61,4); printf("AccountName"); gotoxy(76,4);printf("Available Balance");
			gotoxy(45,5); printf("%d",record[i].recodnum);gotoxy(49,5); printf("%s",record[i].accnum);	
			gotoxy(61,5); printf("%s",record[i].accname); gotoxy(76,5);printf("%.2f",record[i].availbal);
			gotoxy(5,18); printf("Enter new account name: ");
			scanf("%s",record[i].accname);
			gotoxy(5,19); printf("Data modified successfully!");
			gotoxy(45,7); printf("New account");
			gotoxy(45,8); printf("No.");gotoxy(49,8); printf("AccountNo.");	
			gotoxy(61,8); printf("AccountName"); gotoxy(76,8);printf("Available Balance");
			gotoxy(45,9); printf("%d",record[i].recodnum);gotoxy(49,9); printf("%s",record[i].accnum);	
			gotoxy(61,9); printf("%s",record[i].accname); gotoxy(76,9); printf("%.2f",record[i].availbal);
			gotoxy(5,20); printf("Modify again?(Y/N)"); 
			gotoxy(5,21); printf("Enter your choice:");
			scanf(" %c",&c);
		}		
	}
	}
	if(c=='n'||c=='N')
	{ designs();
		gotoxy(5,23); printf("Going back!");
		main();
	}else gotoxy(5,23); printf("Invalid account number!");
}
	
void cashdeposit()
{
		char check[50];
		char c;
		c='y';
	while(c=='y'||c=='Y')
	{
		system("cls");
		designs(); tell();	gotoxy(5,15); printf("~CASH DEPOSIT~");
		gotoxy(5,16); printf("You entered cash deposit.");
		gotoxy(5,17); printf("Enter the account: ");
		scanf("%s",&check);
		for(int i=0;i<num;i++)
		{
		
		if(strcmp(check,record[i].accnum)==0)
		{
			designs();
			gotoxy(45,2); printf("~~~ACCOUNT DETAILS~~~");
			gotoxy(45,3); printf("OLD Account Details:");
			gotoxy(45,4); printf("Name:%s  \t  Balance:%.2f",record[i].accname,record[i].availbal);
			gotoxy(5,18); printf("Enter the amount: ");
			scanf("%f",&record[i].deposit);
			record[i].new_availbal=(record[i].availbal)+record[i].deposit;
			gotoxy(45,5); printf("NEW Account Details:");
			gotoxy(45,6); printf("Name:%s  \t  Balance:%.2f",record[i].accname,record[i].new_availbal);
			gotoxy(5,19); printf("Data is succesffuly added!");
			FILE *fp;
			fp = fopen("listofdeposits.txt", "a");
			
			fprintf(fp ,"%5d            %05s         %20s            %20.2f            %20.2f\n", record[i].recodnum, record[i].accnum, record[i].accname, record[i].deposit, record[i].new_availbal);
			fclose(fp);
			gotoxy(5,20); printf("Deposit again? (Y/N)");
			gotoxy(5,21); printf("Enter your choice:"); scanf(" %c",&c);
		}
		}
			
	}
	if(c=='n'||c=='N')
	{ designs();
		gotoxy(5,23); printf("Going back!");
		Sleep(500);
		main();
	}
}	

void cashwithdrawal()
{
	
	char check[50];
	char c;
	c='y'; designs();
	while(c=='y'||c=='Y')
	{
		system("cls");
		designs(); tell();
		gotoxy(5,15);printf("~CASH WITHDRAWAL~");
		gotoxy(5,16); printf("You entered cash withdrawal");
		gotoxy(5,17);printf("Enter the account: ");
		scanf("%s",&check);
		int i;
		for(i=0;i<num;i++)
		{
			
		if(strcmp(check,record[i].accnum)==0)
		{	designs();
			gotoxy(45,2); printf("~~~ACCOUNT DETAILS~~~");
			gotoxy(45,3); printf("OLD Account Details:\n");
			gotoxy(45,4); printf("%s   %.2f",record[i].accname,record[i].availbal);
			gotoxy(5,18); printf("Enter the amount: ");
			scanf("%f",&record[i].withdraw);
			record[i].new_availbal=(record[i].availbal-record[i].withdraw);
			gotoxy(45,5); printf("NEW Account Details:\n");
			gotoxy(45,6); printf("%s   %.2f",record[i].accname,record[i].new_availbal);
			gotoxy(5,19);printf("Data is succesffuly added!");
				FILE *fp;
			fp = fopen("listofwithdraws.txt", "a");
		
			fprintf(fp ,"%5d            %05s         %20s            %20.2f            %20.2f\n", record[i].recodnum, record[i].accnum, record[i].accname, record[i].withdraw, record[i].new_availbal);
			fclose(fp);
			gotoxy(5,20); printf("Withdraw again? (Y/N)");
			gotoxy(5,21); printf("Enter your choice:");
			scanf(" %c",&c);
		}
		}
	}
	if(c!='Y'||c!='y')
	{
		gotoxy(5,22); printf("Going back!");
		Sleep(500);
		main();
	}	
}
void customers_read()
{ 
	FILE *fp; int i;
	fp=fopen("listofaccounts.txt", "r");
	for (i=0; i<12; i++)
	{
		fscanf(fp," %s", read[i]);
	}
	fscanf(fp, "%d", &num);
	for (i=12; i<17; i++){
	
		fscanf(fp,"%s",read[i]);}
	for(i=0;i<num;i++)
	{
			fscanf(fp,"%d %s %s %f %d %d", &record[i].recodnum, &record[i].accnum, &record[i].accname, &record[i].availbal);
	}
	fclose (fp);
}
void depositlist_read()
{
	customers_read();
	FILE *fp;
	fp= fopen("listofdeposits.txt", "r");
	int i;
	for (i=0; i<19; i++ )
	{
		fscanf(fp, "%s", read2[i]);
	}
	for (i=0; i<num; i++)
	{
				fscanf(fp,"%d %s %s %f %f", &record[i].recodnum, &record[i].accnum, &record[i].accname, &record[i].deposit, &record[i].new_availbal);
	}
	fclose (fp);
}
void withdrawlist_read()
{
	customers_read();
	FILE *fp;
	fp= fopen("listofwithdraws.txt", "r");
	int i;
	for (i=0; i<19; i++ )
	{
		fscanf(fp, "%s", read1[i]);
	}
	for (i=0; i<num; i++)
	{
				fscanf(fp,"%d %s %s %f %f", &record[i].recodnum, &record[i].accnum, &record[i].accname, &record[i].withdraw, &record[i].new_availbal);
	}
	fclose (fp);
}

void listofreports()
{
	
	char pick,c;
	c='y';
	while(c=='Y'||c=='y')
	{
	system("cls"); designs();
	if(aclvl=='s'||aclvl=='S')
	{
		superv();
	} else tell();
	gotoxy(5,15); printf("Display Reports");
	gotoxy(5,16); printf("[1]List of Customers");
	gotoxy(5,17); printf("[2]List of Deposit");
	gotoxy(5,18); printf("[3]List of Withdrawal");
	gotoxy(5,19); printf("Enter your choice:");
	scanf(" %c",&pick);
	if(pick=='1')
			{
				system("cls");
				if(aclvl=='s'||aclvl=='S')
				{
					superv();
				} else tell();
				int i; designs();
				FILE *fp;
				fp=fopen("listOfCustomers.txt", "r+");
				gotoxy(45,2); printf("List of Customer/s\n");
				gotoxy(45,3); printf("No.");gotoxy(49,3); printf("AccountNo.");	
				gotoxy(61,3); printf("AccountName"); gotoxy(76,3);printf("Available Balance");
				float total=0;
				int ctr=0;
				while (fscanf(fp, "%d %s %s %f", &record[i].recodnum, &record[i].accnum, record[i].accname, &record[i].availbal) != EOF) {
				i++;
				num++;
				}
				fprintf(fp,"\tWELCOME TO G-G BANK: THE WORLD'S BEST BANK\n");
				fprintf(fp,"\tList of Customer/s:\n");
				for(i=0;i<num;i++)
				{
				
					total=total+record[i].availbal;
				gotoxy(45,4+ctr); printf("%d",record[i].recodnum); 
				gotoxy(49,4+ctr); printf("%s",record[i].accnum);
				gotoxy(61,4+ctr); printf("%s",record[i].accname);			
				gotoxy(76,4+ctr); printf("%.2f",record[i].availbal);
					ctr+=2;
				}
				gotoxy(45,40); printf("TOTAL: %.2f",total);
				fclose(fp);		
			}
	else if(pick=='2')		
			{	
				system("cls");
				if(aclvl=='s'||aclvl=='S')
				{
					superv();
				} else tell();
				int i; designs(); int ctr=0;
				FILE *fp;
				fp=fopen("listofdeposits.txt", "r+");
				gotoxy(45,2); printf("List of Accounts with Deposit/s\n");
				
				gotoxy(44,3);printf("No."); gotoxy(49,3); printf("AccountNo.");  
				gotoxy(61,3); printf("AccountName"); gotoxy(76,3); printf("AvailBalance");
				gotoxy(92,3); printf("AmtDeposited"); gotoxy(107,3); printf("NewBalance");
				while (fscanf(fp, "%d %s %s %f %f", &record[i].recodnum, &record[i].accnum, &record[i].accname, &record[i].deposit, &record[i].new_availbal) != EOF) {
				i++;
				num++;
				}
				fprintf(fp,"\tWELCOME TO G-G BANK: THE WORLD'S BEST BANK\n");
				fprintf(fp,"\tList of Customer/s with Deposit/s\n");
				for(i=0;i<num;i++)
				{
				if(record[i].deposit!=0)
				{
					
					gotoxy(44,4+ctr); printf("%d",record[i].recodnum); gotoxy(49,4+ctr); printf("%s",record[i].accnum);  
					gotoxy(61,4+ctr); printf("%s",record[i].accname); gotoxy(76,4+ctr); printf("%.2f",record[i].availbal);
					gotoxy(92,4+ctr); printf("%.2f",record[i].deposit); gotoxy(107,4+ctr); printf("%.2f",record[i].new_availbal);
					ctr+=2;	
				}
				
				}
				fclose(fp);	
					
			}
	else if(pick=='3')
			{
				system("cls");
				if(aclvl=='s'||aclvl=='S')
				{
					superv();
				} else tell();
				int i; designs(); int ctr=0;
				FILE *fp;
				fp=fopen("listofwitdraws.txt", "r+");
				gotoxy(45,2); printf("List of Accounts with Withdrawal/s");
				
				gotoxy(44,3);printf("No."); gotoxy(49,3); printf("AccountNo.");  
				gotoxy(61,3); printf("AccountName"); gotoxy(76,3); printf("AvailBalance");
				gotoxy(92,3); printf("AmtWithdraw"); gotoxy(107,3); printf("NewBalance");
				while (fscanf(fp, "%d %s %s %f %f", &record[i].recodnum, &record[i].accnum, &record[i].accname, &record[i].withdraw, &record[i].new_availbal) != EOF) {
				i++;
				num++;
				}
				fprintf(fp,"\tWELCOME TO G-G BANK: THE WORLD'S BEST BANK\n");
				fprintf(fp,"\tList of Customer/s with Deposit/s\n");
				for(i=0;i<num;i++)
				{
				if(record[i].withdraw!=0)
				{
					
					gotoxy(44,4+ctr); printf("%d",record[i].recodnum); gotoxy(49,4+ctr); printf("%s",record[i].accnum);  
					gotoxy(61,4+ctr); printf("%s",record[i].accname); gotoxy(76,4+ctr); printf("%.2f",record[i].availbal);
					gotoxy(92,4+ctr); printf("%.2f",record[i].withdraw); gotoxy(107,4+ctr); printf("%.2f",record[i].new_availbal);
					ctr+=2;	
				}
				
				}
				fclose(fp);	
				
		}
	
	gotoxy(5,20); printf("Display reports(Y/N)?");
	gotoxy(5,21); printf("Your choice:");
	scanf(" %c",&c);
	if(c=='N'||c=='n')
	{
		
		main();
	}	
		

}
}
void menu()
{
	designs();
	gotoxy(5,15);printf("Main Menu");
	
	gotoxy(5,16); 	printf("[1] Account Creation");
	gotoxy(5,17);	printf("[2] Account Maintenance");
	gotoxy(5,18);	printf("[3] Deposit Transaction");
	gotoxy(5,19); 	printf("[4] Withdrawal Transaction");
	gotoxy(5,20);	printf("[5] Reports"); 
	gotoxy(5,21);	printf("[6] Exit");
	
		
	
}
int main()
{
			
	char profile,pick; 
	system("color 0B");
	system("cls");
	designs();  customers_read(); depositlist_read(); withdrawlist_read();
	gotoxy(5,16); printf("Enter User Profile Access Level");
	gotoxy(5,17); printf("(S/s)-Supervisor (T/t)-Teller");
	gotoxy(5,18); printf("Enter your choice: ");//1,2,5,6 -Supervisor 3,4,5,6-Teller
	scanf(" %c",&profile);  aclvl=profile;
	
	
	if(profile=='S'||profile=='s')
	{
		
		system("cls");
		while(pick!=1||pick!='2'||pick=='5'||pick!='6')
		{
		system("cls");
		superv();
		menu();
		gotoxy (5,22); printf("Enter your choice: "); scanf(" %c",&pick);
		
		if(pick=='1')
			accountcreate();
		else if(pick=='2')
			accountmaint();
		else if(pick=='5')
			listofreports();
		else if(pick=='6')
			exit(0);	
}

}

if(profile=='T'||profile=='t')
	{	
		
		system("cls");
		
		while(pick!='3'||pick!='4'||pick=='5'||pick!='6')
	{
		system("cls");
		tell();
		menu(); 
	gotoxy(5,22);	printf("Enter your choice: "); scanf(" %c",&pick);
		if(pick=='3')
			cashdeposit();
		if(pick=='4')
			cashwithdrawal();
		if(pick=='5')
			listofreports();
		if(pick=='6')
			exit(0);

	}
}
if(profile!='S'||profile!='s'||profile!='T'||profile!='t')
	{
		system("cls"); designs();
		gotoxy(5,19); printf("Incorrect input"); Sleep(500);
		main();
	}
	
	
	
	
		
	
}
	



