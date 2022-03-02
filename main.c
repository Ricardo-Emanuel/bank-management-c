# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <time.h>
# include <Windows.h>


// struct of an user of the bank
struct User
{
    char first_name[15];
    char last_name[15];
    long long cpf;
    int password;
    float balance;
    char bank_statement[100][10];

};

// creating the users array
struct User users[10];

// Function that sorts the users by cpf
void sorting_users(int count)
{
    char temp_first_name[15];
    char temp_last_name[15];
    long long temp_cpf;
    int temp_password;
    float temp_balance;
    for (int i = 0; i < count; i++){
        for (int j = 0; j < count - i; j++){
	    if (users[j].cpf > users[j+1].cpf){
	        strcpy(temp_first_name, users[j].first_name);
		strcpy(temp_last_name, users[j].last_name);
		temp_cpf = users[j].cpf;
		temp_password = users[j].password;
		temp_balance = users[j].balance;
		strcpy(users[j].first_name, users[j+1].first_name);
		strcpy(users[j].last_name, users[j+1].last_name);
		users[j].cpf = users[j+1].cpf;
		users[j].password = users[j+1].password;
		users[j].balance = users[j+1].balance;
		strcpy(users[j+1].first_name, temp_first_name);
		strcpy(users[j+1].last_name, temp_last_name);
		users[j+1].cpf = temp_cpf;
		users[j+1].password = temp_password;
		users[j+1].balance = temp_balance;

	    }
	}
    }
}

int linear_search(long long login_cpf, int count)
{
    for (int i = 0; i < count; i++){
        if (login_cpf == users[i].cpf){
	    return i;
	}
    }
    return -1;
}

int binary_search(long long login_cpf, int fim, int inicio)
{
    if (inicio <= fim){
        int meio = (inicio + fim) / 2;

	if (login_cpf == users[meio].cpf)
	    return meio;
	else{
	    if (login_cpf < users[meio].cpf)
	        return binary_search(login_cpf, meio - 1, inicio);
	    else
		return binary_search(login_cpf, fim, meio + 1);
	}
    }
    return -1;
}

// a function to create an user
int create_user(int count)
{
    printf("%s", "Please, type your first name: ");
    scanf("%s", &users[count].first_name);

    printf("%s", "Please, type your last name: ");
    scanf("%s", &users[count].last_name);

    printf("%s", "Please, enter your cpf: ");
    scanf("%lld", &users[count].cpf);

    printf("%s", "Enter your password, please: ");
    scanf("%d", &users[count].password);

    users[count].balance = 0.0;

    sorting_users(count);
    system("cls||clear");
    return 1;
}

// function to validate the creation of an user
void greet_user(int count)
{
    printf("Hello, %s %s", users[count-1].first_name, users[count-1].last_name);
}

int validate_login(int index)
{
    int login_password;

    for (int i = 0; i < 3; i++){
        printf("%s %s: ", "Type your password,", users[index].first_name);
	scanf("%d", &login_password);

	if (login_password == users[index].password){
	    return 1;
	}
    }
    return 0;    
}

void withdraw(int index)
{
    float value;
    printf("\n%s", "Type the value which you want to withdraw: R$");
    scanf("%f", &value);
    if ((users[index].balance - value) < 0){
        printf("\n%s\n", "Sorry, but you can't afford this withdraw!");
    }else{
        users[index].balance -= value;
    }
}

void show_balance(int index)
{
printf("\nR$%.2f\n", users[index].balance);
}

void deposit(int index)
{
    float value;
    printf("\n%s", "Type the value which you want to deposit: R$");
    scanf("%f", &value);
    users[index].balance += value;
}

void login(int index)
{
    system("cls||clear");
    int option;
    while (option != -1){
	printf("\nHello, %s, you're logged in, don't forget to switch off!", users[index].first_name);
	puts("\n------------------------------------------------------------------\n");
	puts("(1) CHECK BALANCE\t (2) DEPOSIT\t (3) WITHDRAW\n");
	puts("Type (-1) to quit.");
	puts("\n------------------------------------------------------------------\n");

        printf("\n%s, what do you want to do today (choose from the menu)? ", users[index].first_name);
	scanf("%d", &option);

	switch(option){
	    case 1:
		show_balance(index);
		Sleep(5);
	        break;
	    case 2:
		deposit(index);
		Sleep(5);
		break;
	    case 3:
		withdraw(index);
		Sleep(5);
		break;
	}
    }
    system("cls||clear");
    printf("\n%s\n", "Ok, see you next time!");
}

// main function
int main()
{
    system("cls||clear");
    int option;
    int count = 0;

    while (option != -1){

        puts("\n\t\t\tMENU");
	puts("\n_________________________________________________________________\n");
	puts("\t\t(1) REGISTER\t| (2) LOGIN\n");
	puts("\t\tType (-1) to quit.");
	puts("\n-----------------------------------------------------------------\n");

        printf("%s", "Hello, how are you? What do you wanna do today? ");
        scanf("%d", &option);

	switch(option){
	    case 1:
		system("cls||clear");

		puts("\n_____________________________________________");
		puts("\n\t\tREGISTER");
		puts("\n---------------------------------------------\n");

	        count += create_user(count);
		break;
	    case 2:
		system("cls||clear");

		puts("\n_____________________________________");
		puts("\n\t\tLOGIN");
		puts("\n-------------------------------------\n");

		sorting_users(count - 1);
		long long login_cpf;
		int index;
		printf("%s", "Type your cpf: ");
		scanf("%lld", &login_cpf);
		if (count <= 4){
		    index = linear_search(login_cpf, count);
		}else{
		    index = binary_search(login_cpf, count - 1, 0);
		}
		int flag_validate = validate_login(index);
		if (flag_validate){
		    login(index);
		}else{
		    printf("You failed!");
		}
		break;
	}
    }
    // Debugging
    for (int i = 0; i < count; i++){
        printf("\n%s %s\n", users[i].first_name, users[i].last_name);
	printf("%lld", users[i].cpf);
    }
    system("cls||clear");
    return 0;
}
