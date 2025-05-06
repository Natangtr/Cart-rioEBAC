#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h>//biblioteca responsavel por cuidar das strings

int registro()//Função responsavel por cadastrar os usuários no sistema. 
{
	    //Início criação de variáveis/string
	    setlocale(LC_ALL, "portuguese"); //definindo a linguagem
        char arquivo [40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];	
		//Final da criação de variáveis/string
		
		printf ("Digite o CPF a ser cadastrado:");//Coletando informação do usuário.
		scanf("%s",cpf);//%s refere-se a string
		strcpy (arquivo,cpf);//responsavel por copiar os valores das strings
		FILE *file;//cria uma variavel,chamou de file(arquivo)
		file= fopen(arquivo, "w");//cria  o arquivo, o "w" é função write(escrever) 
		fprintf(file,cpf); //salvo o valor da variável
		fclose(file);//fecha o arquivo
		
		file=fopen(arquivo,"a"); //abriu o arquivo, a função "a" é para atualizar o arquivo. 
		fprintf (file,",");
		fclose(file);//fechar é importante
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);
		
		file = fopen (arquivo, "a");//está atualizando dentro de file com a função "a" o nome do usuário. 
		fprintf (file, nome);
		fclose(file);
		
		file=fopen(arquivo,"a");
		fprintf (file,",");
		fclose(file);//fechar é importante
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo,"a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file=fopen(arquivo,"a");
		fprintf (file,",");
		fclose(file);//fechar é importante
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);
		
		system("pause");	
}

int consulta()
{
	    setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	    char cpf[40];//criou uma variavel char(string), com 40 
	    char conteudo[200];//criou outravariavel char (string) agora com 200
	    
	    printf("Digite o cpf a ser consultado: ");
	    scanf("%s",cpf);
	    
	    FILE* file;
	    file = fopen(cpf,"r");//esta abrindo o arquivo(file) e lendo ele com a função "r". 
	    
	    if(file == NULL)//caso na comparação ele de NULL, ou seja, não encontre um arquivo compatível com o consultado, ele vai mostrar a mensagem a abaixo.  
	    {
	    	printf("Não foi possivel abrir o arquivo, não localizado.\n");
	    }
	    
		while(fgets(conteudo,200,file) != NULL);//É um laço de repetição, permite mostrar a mensagem abaixo, enquanto nao der NULL na comparação. 
	    {
	    	printf("\n Essas são as informações do usuário !");
	    	printf("%s",conteudo);
	    	printf("\n\n");
	    		
		}
	    	system("pause");
}

int deletar()
{
	char cpf[40];
	printf("Digite o CPF do usuário a ser deletado! ");
	scanf("%s", cpf);
	
	remove(cpf);//responsável por remover o arquivo. 
	
	FILE*file;
	file = fopen(cpf,"r");//esta abrindo o arquivo(file) e lendo ele com a função "r". 
	
	if(file == NULL)//caso na comparação ele de NULL, ou seja, não encontre um arquivo compatível com o consultado, ele vai mostrar a mensagem a abaixo.  
	{
	    printf("O usuário não se encontra no sistema.\n");
		system("pause");
	
	}
}


int main()
  {
    int opcao=0; //definindo variáveis
    int laco=1;
    
    for(laco=1;laco=1;)//laço responsavel por reiniciar o menu a cada operação feita pelo usuário. 
  
       {
       	
      system("cls");//respomsável por limpar a tela. 
  
      setlocale(LC_ALL, "portuguese"); //definindo a linguagem
    
      printf("###Cartório do EBAC###\n\n"); //Início do menu
      printf("Escolha a opção desejada do menu\n\n");
      printf("\t1 - Registrar Nomes\n");
      printf("\t2 - Consultar nomes\n");
      printf("\t3 - Deletar nomes\n\n");
      printf("\t4 - sair do sistema\n\n ");
      
      printf("opção:"); //Fim do menu
    
      scanf ("%d" , &opcao); //Armazenando a escolha do usuário
      system("cls");//Responsável por limpar a tela. 
      
      switch(opcao)//Início da seleção do menu. 
      {
      	case 1:
        registro ();//chamada de funções. 
    	break;
    	
    	case 2:
        consulta();
    	break;
    	
    	case 3:
        deletar();
    	break;
    	
    	case 4:
    	printf("Obrigado por Utilizar o sistema!\n");
    	return 0;
    	break;
    	
    	
    	default:
        printf("Esta opção não esta disponivel\n");
    	system("pause");
    	break;
    	}//fim da seleção 
    
      }


  }
