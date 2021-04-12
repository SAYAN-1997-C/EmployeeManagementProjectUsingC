//------------ALL FUNCTION BODY------
emp* insert(emp *head)
{
	emp *new,*temp;
	int id,i;
	char ch='x',*nm,typ;
	float basic;
	new=(emp *)malloc(sizeof(emp));
	typ=InputType();
	printf("\nEnter the employee id : %c",typ);
	scanf("%d",&id);
	i=InputId(head,typ,id);
	while(1)
	{
		i=InputId(head,typ,id);
		if(i==0)
			break;
		printf("\nPlease enter a unique Id!!This Id is already used!!");
		printf("\nEnter the employee id : %c",typ);
		scanf("%d",&id);

	}	
	getchar();
	nm=NameInput();
	printf("Enter the basic salary : ");
	scanf("%f",&basic);
	new->type=typ;
	new->emp_id=id;
	new->name=nm;
	new->basicSal=basic;
	new->gross=gSal(typ,basic);
	new->next=NULL;
	if(head==NULL)
		head=new;
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;;
		}
		temp->next=new;
	}
	printf("\nInserted Successfully!!\n");
	return head;
}
char* NameInput()
{
	int i=0,j=0;
	char ch='x',*nm,a[100];
	printf("Enter the name : ");
	while(1)
	{
		ch=getchar();
		if(ch=='\n')
			break;
		a[i++]=ch;
	}
	a[i]='\n';
	nm=(char *)malloc(i*sizeof(char));
	i=0;
	while(a[i]!='\n')
	{
		*(nm+j)=a[i];
		i++;
		j++;
	}
	*(nm+j)='\n';
	return nm;
}
char InputType()
{
	int ch;
	char tp;
	while(1)
	{
		printf("\n1.Manager\n2.TechnicalStaff\n3.Labour\nSelect the employee category : ");
		scanf("%d",&ch);
		if(ch==1)
		{
			tp='M';
			break;
		}
		else if(ch==2)
		{
			tp='T';
			break;
		}
		else if(ch==3)
		{
			tp='L';
			break;
		}
		else
			printf("\nPlease select a valid category!!!");
	}
	return tp;
}
int InputId(emp *head,char typ,int id)
{
	int v=0;
	emp *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->type==typ)
		{
			if(ptr->emp_id==id)
			{
				v=1;
				return v;
			}
		}
		ptr=ptr->next;
	}
	return v;
}
  
float gSal(char typ,float basic)
{
	float TA,DA,HRA,Medical,gross;
	if(typ=='M')
	{
		TA=0.15*basic;
		DA=0.7*basic;
		HRA=0.24*basic;
		Medical=0.2*basic;
		gross=basic+TA+DA+HRA+Medical;
		return gross;
	}
	else if(typ=='T')
	{
		TA=0.1*basic;
		DA=0.5*basic;
		HRA=0.2*basic;
		Medical=0.2*basic;
		gross=basic+TA+DA+HRA+Medical;
		return gross;
	}
	else
	{
		TA=0.1*basic;
		DA=0.3*basic;
		HRA=0.1*basic;
		Medical=0.1*basic;
		gross=basic+TA+DA+HRA+Medical;
		return gross;

	}
}
void display(emp *head)
{
	emp *ptr;
	char *nm;
	int i=0;
	if(head==NULL)
	{
		printf("\nNo employee data found!!\n");
		return;
	}
	ptr=head;
	printf("\n--------------ALL EMPLOYEE DETAILS-------------");
	while(ptr!=NULL)
	{
		printf("\nEMPLOYEE ID : %c%d",ptr->type,ptr->emp_id);
		printf("\nEMPLOYEE NAME : ");
		nm=ptr->name;
		i=0;
		while(1)
		{
			if(*(nm+i)=='\n')
				break;
			printf("%c",*(nm+i));
			i++;
		}
		printf("\nBASIC SALARY : %f",ptr->basicSal);
		printf("\nGROSS : %f",ptr->gross);
		ptr=ptr->next;
		puts("\n");
	}
	return;
}
emp* delete(emp *head)
{
	emp *ptr,*temp;
	char ty,*nm;
	int id,i;
	if(head==NULL)
	{
		printf("\nDatabase is already empty!!!NO data found...!!!\n");
		return head;
	}
	ty=InputType();
	printf("\nEnter the employee id : %c",ty);
	scanf("%d",&id);
	temp=ptr=head;
	if(head->type==ty)
	{
		if(head->emp_id==id)
		{
			head=head->next;
			printf("\nDeleted Successfully!!!\n");
			return head;
		}
	}
	while(ptr!=NULL)
	{	
		if(ptr->type==ty)
		{
			if(ptr->emp_id==id)
			{
				temp->next=ptr->next;
				printf("\nDeleted Successfully!!!\n");
				return head;
			}
		}
		temp=ptr;
		ptr=ptr->next;
	}
	printf("\nThis ID have no data!!!!\n");
	return head;
}
void show_a_details(emp *head)
{
	
	emp *ptr;
	char ty,*nm;
	int id,i;
	if(head==NULL)
	{
		printf("\nDatabase is already empty!!!NO data found...!!!\n");
		return ;
	}
	ty=InputType();
	printf("\nEnter the employee id : %c",ty);
	scanf("%d",&id);
	ptr=head;
	while(ptr!=NULL)
	{	
		if(ptr->type==ty)
		{
			if(ptr->emp_id==id)
			{
				printf("\nEMPLOYEE ID : %c%d",ptr->type,ptr->emp_id);
				printf("\nEMPLOYEE NAME : ");
				nm=ptr->name;
				i=0;
				while(1)
				{
					if(*(nm+i)=='\n')
						break;
					printf("%c",*(nm+i));
					i++;
				}
				printf("\nBASIC SALARY : %f",ptr->basicSal);
				printf("\nGROSS : %f\n",ptr->gross);
				return;
			}
		}
		ptr=ptr->next;
	}		
	printf("\nThis ID have no data!!!!\n");
	return;
}
void min_max(emp *head)
{
	emp *ptr;
	float min,max;
	if(head==NULL)
	{
		printf("\nDatabase is already empty!!!NO data found...!!!\n");
		return ;
	}
	min=head->basicSal;
	max=head->basicSal;
	ptr=head;
	while(ptr!=NULL)
	{
		if(max<ptr->basicSal)
			max=ptr->basicSal;
		if(min>ptr->basicSal)
			min=ptr->basicSal;
		ptr=ptr->next;
	}
	printf("\nMAXIMUM SALARY :%f\nMINIMUM SALARY :%f\n",max,min);
	return;	
}

