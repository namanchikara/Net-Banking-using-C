#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct acc
{
    int no;

    char name[100];
    char lname[100];
    char mn[10];

    int pass;

    int balance;

    char aadhaar[12];

    int last1;
    int last2;
    int last3;

    struct acc* next;
}*start=NULL,*last=NULL;

/* *****************************************************************************
*****************************************************************************
    SEARCH FUNCTION
*****************************************************************************
*****************************************************************************/

int search(int no)
{
  struct acc *temp;
  temp = start;

  
    while(temp!= NULL)
    {
      if(temp->no == no)
      {
        return 1;
      }
      temp = temp->next;
    }

  
  return 0;
}

void printn()
{
  printf("\n***************************************************************************************************************************************************\n");
}
/*************************************************************
 ***************** TRANSFER FUNCTION *************************
 * **********************************************************/
int count = 6623;
void delay();
void transfer(int myacc)
{
    struct acc *temp, *temp1;
    temp = start;
    while(temp->no != myacc)
        temp = temp-> next;
    printn();
    printn();
      
    printf("\n*\n*\tEnter your current PIN: ");
    int check;
    
    printn();
      printf("\n*\t");
    scanf("%d",&check);

    if(check == temp->pass)
    { 
       printf("\n\n*\tYour account balance is : Rs.%d\n",temp->balance);
       label:
       printf("\n*\tEnter the account number to which you want to transfer money:\t");
      
      
        printn();
      printf("\n*\t");
       int toacc;
       scanf("%d",&toacc);

       int check;
       check = search(toacc);
       if(check == 0)
        {
            printf("\n*\tAccount not found!\n*\n*\tRedirecting you...\n*");
            goto label;
        }

        else{
            temp1= start;

            while(temp1->no != toacc)
                temp1 = temp1-> next;

            printf("\n*\t\n*\tAccount found!, Owner of account number %d is %s\n*\tEnter the amount(in Rupees) you want to transfer to %d account:\n",temp1->no,temp1->name,toacc);

            int totransfer;
printn();
      printf("\n*\t");
            scanf("%d",&totransfer);

            if(temp->balance < totransfer)
                printf("\n*\n\t*Sorry you don't have enough amount in your account to transfer\n");

            else {
                temp->balance -= totransfer;

                temp1->balance += totransfer;

                temp->last3=temp->last2;
                temp->last2=temp->last1;
                temp->last1=totransfer;


                printf("\n*\n*\tSuccessfully transfered Rs.%d from account number %d to account number %d, Your remaining balance is Rs.%d\n*\n",totransfer,temp->no,temp1->no,temp->balance);
                delay();
            }


        }



    }

    else
    {
        printf("\n*\tIncorrect PIN! Try again\n*\t");
        //delay();
    }


}


/* *****************************************************************************
*****************************************************************************
    PIN CHANGE FUNCTION
*****************************************************************************
*****************************************************************************/

void pin_change(int no)
{
    struct acc *temp;
    temp = start;

    while(temp->no != no)
        temp = temp-> next;
printn();
    
    printf("\n\n\n*\tEnter your current PIN: ");
    int check;
    printn();
      printf("\n*\t");
    scanf("%d",&check);

    if(check == temp->pass)
    {
        printf("\n*\n*\tEnter new PIN");
  printn();
      printf("\n*\t");
        scanf("%d",&temp->pass);
printn();
      printn();
      
        printf("\n*\n*\tDear %s, PIN of your account %d has been changed successfully!\n*\t\n*\t",temp->name,temp->no);
        printn();
      printn();
      delay();
    }

    else
    {
        printf("\n*\n*\tIncorrect PIN! Try again");
        delay();
    }
}



/* *****************************************************************************
*****************************************************************************
    Delay FUNCTION
*****************************************************************************
*****************************************************************************/


void delay()
{
    int c,d;
     for (c = 1; c <= 32767; c++)
       for (d = 1; d <= 32767; d++)
       {}
}

/* *****************************************************************************
*****************************************************************************
    BALANCE FUNCTION
*****************************************************************************
*****************************************************************************/

void print_balance(int no)
{
  struct acc *temp;
  temp = start;

  while(temp->no != no)
    temp = temp-> next;
  printf("\n*************************************************\n");
  printf("\n*\n*\tHello %s, balance of your account no %d is %d\n",temp->name,temp->no,temp->balance);
  delay();
}



/* *****************************************************************************
*****************************************************************************
    Admins FUNCTION
*****************************************************************************
*****************************************************************************/

void admins()
{
  struct acc *temp,*temp1;
  label:
  temp=start;
  temp1=last;

  int choice;
  printf("\n\n*************************************************\n");
  printf("\n*\t1. Print all accounts");
  printf("\n*\t2. Search for an account in record");
  printf("\n*\t10. Exit");


printn();
      printf("\n*\t");
  scanf("%d",&choice);
  printf("\n*************************************************\n");

  int ch,c;
  switch(choice)
  {
    case 1: if(start==NULL){
                printf("\n*************************************************\n");
                printf("\n*\n*\tNo accounts in database\n");
                printf("\n*************************************************\n");

            }
            else while(temp!=NULL)
                {
                  printf("\n*\t%d",temp->no);
                  temp=temp->next;
                }
            goto label;

    case 2: printn();
      printf("\n*\t");
            scanf("%d",&ch);
            c=search(ch);

            if(c==0)
              {
                    printf("\n*************************************************\n");
                    printf("\n*\tNot found\n");

              }

            else if(c==1)
              {

                  printf("\n*************************************************\n");
                  printf("\n*\tFound\n",c);

              }

            goto label;

    case 10: return;
  }

  return;

}


/* *****************************************************************************
*****************************************************************************
    CREATE ACCOUNT FUNCTION
*****************************************************************************
*****************************************************************************/

void createaccount()
{
  struct acc *temp;
  temp = (struct acc *)malloc(sizeof(struct acc));

  int i;
  printf("\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*\n*");
  printn();
  printf("\n**********************************************************     Create a new Account     ***********************************************************\n");
  printn();
  
  printf("\n*\tEnter your first name please: ");
  printn();
      printf("\n*\t");
  scanf("%s",temp->name);
  printf("\n*\tNow please enter your last name: ");
  printn();
      printf("\n*\t");
  scanf("%s",temp->lname);


  printf("\n*\tHello %s!\n*\tWhile we create your account please provide us your Mobile number: ",temp->name);
  lacoste:
  printn();
      printf("\n*\t");
  scanf("%s",temp->mn);
  
  int len;
  
  len = strlen(temp->mn);
  if(len != 10)
    {
      printf("\n*\tInvalid Mobile number, Your mobile number contains %d numbers? Please enter a valid mobile number:\n",len);
      goto lacoste;
    }
  
  printf("\n\n*\t%s is %s your Mobile number?\nEnter YES if it is, NO to re-enter your mobile number",temp->name,temp->mn);
  char choice[100];
  valid1:
  printn();
      printf("\n*\t");
  scanf("%s",choice);

  if(choice[0]=='y' || choice[0]=='Y')
  printf("\n*\t%s has been set as your mobile number!",temp->mn);

  else if(choice[0]=='n' || choice[0]=='N')
  {
    printf("\n*\tIt's alright we all make mistakes, please re-enter your mobile number again: ");
    goto lacoste;
  }

  else {
    printf("\n*\tEnter a valid choice! Yes or No\n*\t");
    goto valid1;
  }


  printf("\n*\t\n*\t\n*\tEnter your Aadhaar number as it's required everywhere in India these days!: \n*\t");
  printn();
      printf("\n*\t");
  scanf("%s",&temp->aadhaar);

  reset2:
  printf("\n*\t\n*\t%s has been set as your Aadhaar number \n*\n*\tIs it correct? if yes then enter YES else to change it enter NO",temp->aadhaar);


  valid2:
  printf("\n*\t");
  scanf("%s",choice);

  if(choice[0]=='y' || choice[0]=='Y')
  printf("\n*\t%s has been set as your Aadhaar number!\n",temp->aadhaar);

  else if(choice[0]=='n' || choice[0]=='N')
  {
    printf("\n*\tIt's alright we all make mistakes, please re-enter your Aadhaar number again: ");
    printn();
      printf("\n*\t");
    scanf("%s",temp->aadhaar);
    goto reset2;
  }

  else {
    printf("\n*\tEnter a valid choice! Yes or No\n*\t");
    goto valid2;
  }
  
  temp->no = count;
  count++;
  
  if(start == NULL)
    {
      start = temp;
      last = temp;
      last->next=NULL;
    }
  else
  {
    
    last->next = temp;
  }
  
  printn();
      

  printf("\n*\t%d has been allocated as your Account number, %s kindly note it down somewhere!\n*\t",temp->no,temp->name);
printn();
      delay();
printn();
      
  printf("\n*\tNow enter your desired PIN for your Account\n*\t");
  printf("\n*\t");
  scanf("%d",&temp->pass);


  temp->balance=1000;

  printf("\n*\t%s, Your Account has been created successfully!\n*\tWe have deposited Rupees 1000/- in your Account!",temp->name); delay();

  temp->last1 = 0;
  temp->last2 = 0;
  temp->last3 = 0;

  return;
}


/* *****************************************************************************
*****************************************************************************
    MAIN FUNCTION
*****************************************************************************
*****************************************************************************/

int main(void)
{

  struct acc *admin,*temp1,*temp2,*temp3;
 
  admin = (struct acc *)malloc(sizeof(struct acc));
  admin->no=9012;
  admin->pass=1337;


  beginagain:
  printf("\n\n\n\n\n***************************************************************************************************************************************************\n");
  printf("\n**********************************************************     Welcome to Net Banking Services    **************************************************\n");
  printn();
  printn();
  printn();
  printf("\n*\n*\n*\tAre you :\n*\n*\t1. Existing user?\n*\n*\t2. New user?\n*\n*\tEnter your choice as 1 or 2 please \n*");
  int whoami;
  int choice;
  
  printn();
  printn();
  
  printf("\n*\t");
  scanf("%d",&whoami);

  if(whoami != 1 && whoami != 2 && whoami != 9012)
    { 
      printn();
      printf("\n*\n*\tInvalid choice! Redirecting you back...\n*");
      printn();
      
      delay();
      goto beginagain;
    }

  if(whoami==1)
  {
        printf("\n*\n*\tEnter your Account number: ");
        int myacc,exist=1;
      printn();
      printf("\n*\t");
        scanf("%d",&myacc);

        exist=search(myacc);

        if(exist == 0)
        {
          printn();
  printn();
          
          printf("\n*\n*\n*\n*\tAccount number %d does not exist! Please create a new Account and try again!\n*\n*",myacc);
          
          goto beginagain;
        }


          whatnow:
          
          printn();
          printf("\n*\t1. Account Balance\n",exist);
          printf("\n*\t2. Pin Change\n");
          printf("\n*\t3. Transfer money to another account\n");
          printf("\n*\t4. Last three transactions\n");
          printf("\n*\t5. Exit\n");
          printf("\n*\tPlease Enter your choice:\n");


          struct acc *account;
          printn();
          printf("\n*\t");
          scanf("%d",&choice);

          
          switch(choice)
          {
            case 1: print_balance(myacc); goto whatnow;

            case 2: pin_change(myacc); goto whatnow;

            case 3: transfer(myacc); goto whatnow;

            case 4:

                    account= start;
                    while(account->no != myacc)
                        account = account-> next;
                    printn();
      
                    printf("\n*\n*\t%d\t%d\t%d\n*\n*",account->last1,account->last2,account->last3);
                    delay();
                    goto whatnow;

            case 5: goto beginagain;

            default: printf("\n*\n*\tInvalid option, Try again"); goto whatnow;

          }
  }

  if(whoami==2)
  {
    createaccount();
    goto beginagain;
  }


  if(whoami == 9012)
  {
    printf("\n*\n*\tOh Admin?!, Enter password to confirm: \n*\t");
    int check;
    valid2:
    printn();
      printf("\n*\t");
    scanf("%d",&check);

    if(check == admin->pass)
      {
          admins();
          goto beginagain;
      }

    else
    {
      printf("\n*\n*\tOops, wrong password, try again:\n*\n*\t ");
      goto valid2;
    }
  }

  return 0;
}
