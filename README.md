# bank-management-c
simulando uma aplicacao basica de um banco em C para treinar e aprender

## Ideia inicial
um aplicativo de banco, incialmente feito para consulta de saldo em uma conta mas pretendo ir adicionando novas features, como: **Deposito e saque, consulta de extrato, transferencia entre usuarios.**

## Estrutura inicial
1. é mostrado um menu com as opcoes de **cadastro** ou **login**. Inicialmente o cadastro deve ser feito toda vez que o app rodar, mas existe o plano de implementar um database que guarde os dados mesmo quando o app parar;
2. o cadastro é feito por uma funcao que salva a struct gerada em um array de structs;
3. ao fazer o login é feita uma ordenacao do array de structs pelo cpf dos usuarios e uma busca basica pelo cpf de login;
4. ainda preciso implementar a funcao de validacao de login, ou seja, cpf e senha;
5. caso o login seja permitido o usuário entrará em uma funcao loop com a interface de usuario e as acoes que ele pode tomar;
5. criarei um login admin para conseguir administrar os usuarios cadastrados e seus dados;
