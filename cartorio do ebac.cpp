#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h>//biblioteca responsavel por cuidar das strings

int registro()//Fun��o responsavel por cadastrar os usu�rios no sistema. 
{
	    //In�cio cria��o de vari�veis/string
	    setlocale(LC_ALL, "portuguese"); //definindo a linguagem
        char arquivo [40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];	
		//Final da cria��o de vari�veis/string
		
		printf ("Digite o CPF a ser cadastrado:");//Coletando informa��o do usu�rio.
		scanf("%s",cpf);//%s refere-se a string
		strcpy (arquivo,cpf);//responsavel por copiar os valores das strings
		FILE *file;//cria uma variavel,chamou de file(arquivo)
		file= fopen(arquivo, "w");//cria  o arquivo, o "w" � fun��o write(escrever) 
		fprintf(file,cpf); //salvo o valor da vari�vel
		fclose(file);//fecha o arquivo
		
		file=fopen(arquivo,"a"); //abriu o arquivo, a fun��o "a" � para atualizar o arquivo. 
		fprintf (file,",");
		fclose(file);//fechar � importante
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);
		
		file = fopen (arquivo, "a");//est� atualizando dentro de file com a fun��o "a" o nome do usu�rio. 
		fprintf (file, nome);
		fclose(file);
		
		file=fopen(arquivo,"a");
		fprintf (file,",");
		fclose(file);//fechar � importante
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo,"a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file=fopen(arquivo,"a");
		fprintf (file,",");
		fclose(file);//fechar � importante
		
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
	    file = fopen(cpf,"r");//esta abrindo o arquivo(file) e lendo ele com a fun��o "r". 
	    
	    if(file == NULL)//caso na compara��o ele de NULL, ou seja, n�o encontre um arquivo compat�vel com o consultado, ele vai mostrar a mensagem a abaixo.  
	    {
	    	printf("N�o foi possivel abrir o arquivo, n�o localizado.\n");
	    }
	    
		while(fgets(conteudo,200,file) != NULL);//� um la�o de repeti��o, permite mostrar a mensagem abaixo, enquanto nao der NULL na compara��o. 
	    {
	    	printf("\n Essas s�o as informa��es do usu�rio !");
	    	printf("%s",conteudo);
	    	printf("\n\n");
	    		
		}
	    	system("pause");
}

int deletar()
{
	char cpf[40];
	printf("Digite o CPF do usu�rio a ser deletado! ");
	scanf("%s", cpf);
	
	remove(cpf);//respons�vel por remover o arquivo. 
	
	FILE*file;
	file = fopen(cpf,"r");//esta abrindo o arquivo(file) e lendo ele com a fun��o "r". 
	
	if(file == NULL)//caso na compara��o ele de NULL, ou seja, n�o encontre um arquivo compat�vel com o consultado, ele vai mostrar a mensagem a abaixo.  
	{
	    printf("O usu�rio n�o se encontra no sistema.\n");
		system("pause");
	
	}
}


int main()
  {
    int opcao=0; //definindo vari�veis
    int laco=1;
    
    for(laco=1;laco=1;)//la�o responsavel por reiniciar o menu a cada opera��o feita pelo usu�rio. 
  
       {
       	
      system("cls");//respoms�vel por limpar a tela. 
  
      setlocale(LC_ALL, "portuguese"); //definindo a linguagem
    
      printf("###Cart�rio do EBAC###\n\n"); //In�cio do menu
      printf("Escolha a op��o desejada do menu\n\n");
      printf("\t1 - Registrar Nomes\n");
      printf("\t2 - Consultar nomes\n");
      printf("\t3 - Deletar nomes\n\n");
      printf("\t4 - sair do sistema\n\n ");
      
      printf("op��o:"); //Fim do menu
    
      scanf ("%d" , &opcao); //Armazenando a escolha do usu�rio
      system("cls");//Respons�vel por limpar a tela. 
      
      switch(opcao)//In�cio da sele��o do menu. 
      {
      	case 1:
        registro ();//chamada de fun��es. 
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
        printf("Esta op��o n�o esta disponivel\n");
    	system("pause");
    	break;
    	}//fim da sele��o 
    
      }


  }
