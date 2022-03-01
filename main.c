# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <time.h>

// struct of an user of the bank
struct User
{
    char first_name[15];
    char last_name[15];
    int cpf;
    int cpf_digits;
    int password;
    int balance;
    char bank_statement[100][10];

};

// creating the users array
struct User users[10];

// Function that sorts the users by cpf
void sorting_users(int count)
{
    char temp_first_name[15];
    char temp_last_name[15];
    int temp_cpf;
    int temp_cpf_digits;
    int temp_password;
    int temp_balance;
    for (int i = 0; i < count; i++){
        for (int j = 0; j < count - i; j++){
	    if (users[j].cpf > users[j+1].cpf){
	        strcpy(temp_first_name, users[j].first_name);
		strcpy(temp_last_name, users[j].last_name);
		temp_cpf = users[j].cpf;
		temp_cpf_digits = users[j].cpf_digits;
		temp_password = users[j].password;
		temp_balance = users[j].balance;
		strcpy(users[j].first_name, users[j+1].first_name);
		strcpy(users[j].last_name, users[j+1].last_name);
		users[j].cpf = users[j+1].cpf;
		users[j].cpf_digits = users[j+1].cpf_digits;
		users[j].password = users[j+1].password;
		users[j].balance = users[j+1].balance;
		strcpy(users[j+1].first_name, temp_first_name);
		strcpy(users[j+1].last_name, temp_last_name);
		users[j+1].cpf = temp_cpf;
		users[j+1].cpf_digits = temp_cpf_digits;
		users[j+1].password = temp_password;
		users[j+1].balance = temp_balance;

	    }
	}
    }
}

int linear_search(int login_cpf, int count)
{
    for (int i = 0; i < count; i++){
        if (login_cpf == users[i].cpf){
	    return i;
	}
    }
    return -1;
}

int binary_search(int login_cpf, int fim, int inicio)
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

    printf("%s", "Please, enter your cpf without the last two digits: ");
    scanf("%d", &users[count].cpf);

    printf("%s", "Please, enter the last two digits of your cpf: ");
    scanf("%d", &users[count].cpf_digits);

    printf("%s", "Enter your password, please: ");
    scanf("%d", &users[count].password);

    users[count].balance = 0;

    sorting_users(count);

    return 1;
}

// function to validate the creation of an user
void greet_user(int count)
{
    printf("Hello, %s %s", users[count-1].first_name, users[count-1].last_name);
}

//void validate_login(int password, int cpf)
//{
    
//}

//void login(int cpf)
//{
    
//}

// main function
int main()
{
    int option;
    int count = 0;

    while (option != -1){
        printf("\n\n%s", "Hello, how are you? What do you wanna do today? ");
        scanf("%d", &option);

	switch(option){
	    case 1:
	        count += create_user(count);
		break;
	    case 2:
		sorting_users(count - 1);
		int login_cpf;
		int index;
		printf("%s", "Type your cpf: ");
		scanf("%d", &login_cpf);
		if (count <= 4){
		    index = linear_search(login_cpf, count);
		}else{
		    index = binary_search(login_cpf, count - 1, 0);
		}
		printf("%d", index);
		//login();
		break;
	}
    }
    // Debugging
    for (int i = 0; i < count; i++){
        printf("\n%s %s\n", users[i].first_name, users[i].last_name);
	printf("%d", users[i].cpf);
    }
    return 0;
}
