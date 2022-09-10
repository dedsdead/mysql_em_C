/* 
 * File:   main.c
 * Author: Prof. Wagner Rodrigo Weinert
 *
 * Created on 04 de novembro de 2021
 * Banco de Dados programac
 * create table carro(placa varchar(7) not null, modelo varchar(45) not null, primary key(placa));
 * INSTRUÇÕES PARA Kubuntu ou Debian
  * instalar cliente mysql: apt-get install libmysqlclient-dev 
 * compilar com o seguinte comando: gcc main.c -lmysqlclient -o main
 */

#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void main(void){
	MYSQL conexao;
	int res;
	MYSQL_RES *resp;
	MYSQL_ROW linhas;
	MYSQL_FIELD *campos;
	int conta; //Contador comum
	
	int opc = 1; //OPCAO DO MENU
	
	int codigo;
	char[] nome;
	int telefone;
	char[] email;

	int novo; //ALTERAR INT
	char[] alterar; //ALTERAR STRING

	char[255] query;
	
	
	mysql_init(&conexao);
	if ( mysql_real_connect(&conexao, "wagnerweinert.com.br", "tads21_andrerosa", "tads21_andrerosa", "tads21_andrerosa", 3306, NULL, 0) ){
		printf("conectado com sucesso!\n");
		
		cria_tabelas();
		
		//MENU GERAL
		while(opc != 0){
			printf("ESCOLHA UMA OPCAO: \n");
			printf("1: CADASTRAR\n");
			printf("2: BUSCAR\n");
			printf("3: ALTERAR\n");
			printf("4: EXCLUIR\n");
			
			printf("0: SAIR\n");
			
			scanf(%i, &opc);
			
			//MENU DE CADASTRO
			switch(opc){
				case 1:
					printf("ESCOLHA UMA OPCAO: \n");
					printf("1: NOVO CONTATO\n");
					printf("2: ADICIONAR TELEFONE\n");
					printf("3: ADICIONAR EMAIL\n");
					
					printf("5: VOLTAR\n");
					
					scanf(%i, &opc);
					
					switch(opc){
						case 1:
							printf("DIGITE O NOME DO CONTATO: \n");
							scanf(%s, nome);
							
							cria_contato(nome);
							
						break;
						
						case 2:
							printf("DIGITE O NOME DO CONTATO PARA ADICIONAR UM TELEFONE: \n");
							scanf(%s, nome);
							
							id = busca_contato_nome(nome);
							
							printf("DIGITE O NUMERO DE TELEFONE: \n");
							scanf(%d, &telefone);
							
							adiciona_telefone(id, telefone);
							
						break;
						
						case 3:
							printf("DIGITE O NOME DO CONTATO PARA ADICIONAR UM EMAIL: \n");
							scanf(%s, nome);
							
							id = retorna_contato_id(nome);
							
							printf("DIGITE O EMAIL: \n");
							scanf(%s, email);
							
							adiciona_email(id, email);
							
						break;
					}
					
				break;
				
				//MENU DE BUSCA
				case 2:
					printf("ESCOLHA UMA OPCAO: \n");
					printf("1: BUSCAR POR CODIGO\n");
					printf("2: BUSCAR POR NOME\n");
					printf("3: BUSCAR POR TELEFONE\n");
					printf("4: BUSCAR POR EMAIL\n");
					
					printf("5: VOLTAR\n");
					
					scanf(%i, &opc);
					
					switch(opc){
						case 1:
							printf("DIGITE O CODIGO PARA BUSCAR O CONTATO: \n");
							scanf(%d, &codigo);
							
							busca_contato_codigo(codigo);
							
						break;
				
						case 2:
							printf("DIGITE O NOME PARA BUSCAR O CONTATO: \n");
							scanf(%s, nome);
							
							busca_contato_nome(nome);
							
						break;
						
						case 3:
							printf("DIGITE O TELEFONE PARA BUSCAR O CONTATO: \n");
							scanf(%d, &telefone);
							
							busca_contato_telefone(telefone);
							
						break;
				
						case 4:
							printf("DIGITE O EMAIL PARA BUSCAR O CONTATO: \n");
							scanf(%s, email);
							
							busca_contato_email(email);
							
						break;
					}
					
				break;
				
				//MENU DE ALTERAÇÃO
				case 3:
					printf("ESCOLHA UMA OPCAO: \n");
					printf("1: ALTERAR CONTATO\n");
					printf("2: ALTERAR TELEFONE\n");
					printf("3: ALTERAR EMAIL\n");

					printf("5: VOLTAR\n");

					scanf(%i, &opc);

					switch (opc){
						case 1:
							printf("DIGITE O NOME DO CONTATO A ALTERAR: \n");
							
							scanf(%s, alterar);

							printf("DIGITE O NOVO NOME: \n");
							
							scanf(%s, nome);
								
							altera_contato_nome(alterar, nome);

						break;

						case 2:
							printf("DIGITE O TELEFONE A ALTERAR: \n");
							
							scanf(%d, &telefone);

							printf("DIGITE O NOVO TELEFONE: \n");
							
							scanf(%d, &novo);
								
							altera_telefone(novo, telefone);

						break;

						case 3:
							printf("DIGITE O EMAIL A ALTERAR: \n");
							
							scanf(%s, email);

							printf("DIGITE O NOVO EMAIL: \n");
							
							scanf(%s, alterar);
								
							altera_email(alterar, email);

						break;
					
					}

				break;
				
				//MENU DE EXCLUSÃO
				case 4:
					printf("ESCOLHA UMA OPCAO: \n");
					printf("1: DELETAR CONTATO\n");
					printf("2: DELETAR TELEFONE\n");
					printf("3: DELETAR EMAIL\n");

					printf("5: VOLTAR\n");

					scanf(%i, &opc);

					switch (opc){
						case 1:
							printf("DIGITE O NOME DO CONTATO A EXCLUIR: \n");
							
							scanf(%s, nome);
								
							exclui_contato_nome(nome);

						break;

						case 2:
							printf("DIGITE O TELEFONE A EXCLUIR: \n");
							
							scanf(%d, &telefone);
								
							exclui_telefone(telefone);

						break;

						case 3:
							printf("DIGITE O EMAIL A EXCLUIR: \n");
							
							scanf(%s, email);
								
							exclui_email(email);

						break;
					
					}
					
				break;
			}
			
		}
	
		
		/*
							!!!!!!!!!!!!!!!
		
		Alterando um valor                             
		res=mysql_query(&conexao,"update carro set modelo='Pampa' where placa like 'AWX1313'");
	    	if (!res) printf("Registros alterados %d\n", mysql_affected_rows(&conexao));
	    	else printf("Erro na alteração %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
		
							!!!!!!!!!!!!!!!
		
		*/
		
		mysql_close(&conexao);
		
	} else {
		printf("FALHA DE CONEXAO\n");
	    printf("ERRO %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
	    
	}
	
	void cria_tabelas(){
		create table programac_agenda(
			codigo int not null AUTO_INCREMENT,
			nome varchar(45) not null,
			primary key(codigo)
		);
		
		create table programac_telefone(
			telefone int not null,
			codigo int not null,
			primary key(telefone),
			foreign key(codigo) references programac_agenda(codigo)
			on delete cascade
		);
		
		create table programac_email(
			email varchar(100) not null,
			codigo int not null,
			primary key(email),
			foreign key(codigo) references programac_agenda(codigo)
			on delete cascade
		);
	}
	
	//cria um contato
	void cria_contato(char[] nome){
		sprintf(query, "insert into programac_agenda values ('%s');", nome);

		res = mysql_query(&conexao, query);
		if (!res) printf("CONTATO CRIADO COM SUCESSO %d\n");
		else printf("ERRO AO CRIAR CONTATO %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
	}
	
	//adiciona um telefone ao contato informado
	void adiciona_telefone(int id, int telefone){
		sprintf(query, "insert into programac_telefone values (%d, %d);", telefone, id);

		res = mysql_query(&conexao, query);
		if (!res) printf("TELEFONE ADICIONADO COM SUCESSO %d\n");
		else printf("ERRO AO CRIAR CONTATO %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
	}
	
	//adiciona um email ao contato informado
	vo%d ad, codigoiciona_email(int id, char[] email){
		sprintf(query, "insert into programac_email values ('%s', %d);", email, id);

		res = mysql_query(&conexao, query);
		if (!res) printf("EMAIL ADICIONADO COM SUCESSO %d\n");
		else printf("ERRO AO CRIAR CONTATO %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
	}
	
	//busca o contato pelo nome e retorna o id
	int retorna_contato_id(char[] nome){
		sprintf(query, "select codigo from programac_agenda where nome like ('%s');", nome);

		if (mysql_query(&conexao, query))
	    	printf("ERRO: %s\n",mysql_error(&conexao));
		else {
 			resp = mysql_store_result(&conexao);
 			
			if (resp) {
   				linhas=mysql_fetch_row(resp);
   				//retorna a linha na posicao 0, que é o id
   				return linhas[0];
        	}
  			mysql_free_result(resp);
		}
		
	}
	
	//busca o contato pelo codigo e imprime na tela
	void busca_contato_codigo(int codigo){
		sprintf(query, "select * from programac_agenda a inner join programac_telefone t inner join programac_email e on a.codigo=t.codigo and a.codigo=e.codigo and a.codigo=%d;", codigo);

		if (mysql_query(&conexao, query))
	    	printf("Erro: %s\n",mysql_error(&conexao));
		else {
 			resp = mysql_store_result(&conexao);//recebe a consulta
 			//se houver consulta
			if (resp) {
   				//passa os dados dos campos para a variável campos
   				//escreve na tela os nomes dos campos dando
   				//um tab somente
   				campos = mysql_fetch_fields(resp);
   				for (conta=0;conta<mysql_num_fields(resp);conta++) {
      				printf("%s",(campos[conta]).name);
      				if (mysql_num_fields(resp)>1)
          				printf("\t");
      			}
            	printf("\n");  
            	//enquanto retornar registros, conta até o
		    	//número de colunas que a tabela tem e escreve na
      			//tela com um tab, depois pula a linha e tenta
      			//pegar outro registros
      			while ((linhas=mysql_fetch_row(resp)) != NULL){
         			for (conta=0;conta<mysql_num_fields(resp);conta++)
            			printf("%s\t",linhas[conta]);
         			printf("\n");
      			}
        	}
  			mysql_free_result(resp);//limpa a variável do resultado: resp
		}
		
	}
	
	//busca o contato pelo nome e imprime na tela
	void busca_contato_nome(char[] nome){
		sprintf(query, "select * from programac_agenda a inner join programac_telefone t inner join programac_email e on a.codigo=t.codigo and a.codigo=e.codigo and a.nome like ('%s');", nome);

		if (mysql_query(&conexao, query))
	    	printf("ERRO: %s\n",mysql_error(&conexao));
		else {
 			resp = mysql_store_result(&conexao);
			if (resp) {
   				campos = mysql_fetch_fields(resp);
   				for (conta=0;conta<mysql_num_fields(resp);conta++) {
      				printf("%s",(campos[conta]).name);
      				if (mysql_num_fields(resp)>1)
          				printf("\t");
      			}
            	printf("\n");  
      			while ((linhas=mysql_fetch_row(resp)) != NULL){
         			for (conta=0;conta<mysql_num_fields(resp);conta++)
            			printf("%s\t",linhas[conta]);
         			printf("\n");
      			}
        	}
  			mysql_free_result(resp);
		}
		
	}
	
	//busca o contato pelo telefone e imprime na tela
	void busca_contato_telefone(int telefone){
		sprintf(query, "select * from programac_agenda a inner join programac_telefone t inner join programac_email e on a.codigo=t.codigo and a.codigo=e.codigo and t.telefone=%d;", telefone);

		if (mysql_query(&conexao, query))
	    	printf("ERRO: %s\n",mysql_error(&conexao));
		else {
 			resp = mysql_store_result(&conexao);
			if (resp) {
   				campos = mysql_fetch_fields(resp);
   				for (conta=0;conta<mysql_num_fields(resp);conta++) {
      				printf("%s",(campos[conta]).name);
      				if (mysql_num_fields(resp)>1)
          				printf("\t");
      			}
            	printf("\n");  
      			while ((linhas=mysql_fetch_row(resp)) != NULL){
         			for (conta=0;conta<mysql_num_fields(resp);conta++)
            			printf("%s\t",linhas[conta]);
         			printf("\n");
      			}
        	}
  			mysql_free_result(resp);
		}
		
	}
	
	//busca o contato pelo email e imprime na tela
	void busca_contato_email(char[] email){
		sprintf(query, "select * from programac_agenda a inner join programac_telefone t inner join programac_email e on a.codigo=t.codigo and a.codigo=e.codigo and e.email like ('%s');", email);

		if (mysql_query(&conexao, query))
	    	printf("ERRO: %s\n",mysql_error(&conexao));
		else {
 			resp = mysql_store_result(&conexao);
			if (resp) {
   				campos = mysql_fetch_fields(resp);
   				for (conta=0;conta<mysql_num_fields(resp);conta++) {
      				printf("%s",(campos[conta]).name);
      				if (mysql_num_fields(resp)>1)
          				printf("\t");
      			}
            	printf("\n");  
      			while ((linhas=mysql_fetch_row(resp)) != NULL){
         			for (conta=0;conta<mysql_num_fields(resp);conta++)
            			printf("%s\t",linhas[conta]);
         			printf("\n");
      			}
        	}
  			mysql_free_result(resp);
		}
		
	}

	//alterar o contato pelo nome
	void altera_contato_nome (char[] alterar, char[] nome){
		sprintf(query, "update programac_agenda set nome=('%s') where nome like ('%s')", alterar, nome);

		res=mysql_query(&conexao, query);
	    if (!res) printf("SUCESSO NA EXCLUSÃO %d\n");
	    else printf("ERRO NA EXCLUSÃO %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));     
		
	}

	//alterar o telefone
	void altera_telefone (int novo, int telefone){
		sprintf(query, "delete from programac_telefone set telefone=%d where telefone=%d", alterar, telefone);

		res=mysql_query(&conexao, query);
	    if (!res) printf("SUCESSO NA EXCLUSÃO %d\n");
	    else printf("ERRO NA EXCLUSÃO %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));     
		
	}

	//alterar o email
	void altera_email (char[] alterar, char[] email){
		sprintf(query, "delete from programac_email set email=('%s') where email like ('%s')", alterar, email);

		res=mysql_query(&conexao, query);
	    if (!res) printf("SUCESSO NA EXCLUSÃO %d\n");
	    else printf("ERRO NA EXCLUSÃO %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));     
		
	}
	
	//excluir o contato pelo nome
	void exclui_contato_nome (char[] nome){
		sprintf(query, "delete from programac_agenda where nome like ('%s')", nome);

		res=mysql_query(&conexao, query);
	    if (!res) printf("SUCESSO NA EXCLUSÃO %d\n");
	    else printf("ERRO NA EXCLUSÃO %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));     
		
	}

	//excluir o telefone
	void exclui_telefone (int telefone){
		sprintf(query, "delete from programac_telefone where telefone=%d", telefone);

		res=mysql_query(&conexao, query);
	    if (!res) printf("SUCESSO NA EXCLUSÃO %d\n");
	    else printf("ERRO NA EXCLUSÃO %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));     
		
	}

	//excluir o email
	void exclui_email (char[] email){
		sprintf(query, "delete from programac_email where email like ('%s')", email);

		res=mysql_query(&conexao, query);
	    if (!res) printf("SUCESSO NA EXCLUSÃO %d\n");
	    else printf("ERRO NA EXCLUSÃO %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));     
		
	}
	 
}
