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
	
	
	mysql_init(&conexao);
	if ( mysql_real_connect(&conexao, "wagnerweinert.com.br", "tads21_andrerosa", "tads21_andrerosa", "tads21_andrerosa", 3306, NULL, 0) ){
		printf("conectado com sucesso!\n");
		
		cria_tabelas();
		
		while(opc != 0){
			printf("ESCOLHA UMA OPCAO: \n");
			printf("1: CADASTRAR\n");
			printf("2: BUSCAR\n");
			printf("3: ALTERAR\n");
			printf("4: EXCLUIR\n");
			
			printf("0: SAIR\n");
			
			scanf(%i, &opc);
			
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
				
				case 3:
					
				break;
				
				case 4:
					printf("DIGITE O NOME DO CONTATO A EXCLUIR: \n");
							scanf(%s, nome);
							
							exclui_contato_nome(nome);
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
		);
		
		create table programac_email(
			email varchar(100) not null,
			codigo int not null,
			primary key(email),
			foreign key(codigo) references programac_agenda(codigo)
		);
	}
	
	//cria um contato
	void cria_contato(char[] nome){
		res = mysql_query(&conexao,"insert into programac_agenda values (nome);");
		if (!res) printf("CONTATO CRIADO COM SUCESSO %d\n");
		else printf("ERRO AO CRIAR CONTATO %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
	}
	
	//adiciona um telefone ao contato informado
	void adiciona_telefone(int id, int telefone){
		res = mysql_query(&conexao,"insert into programac_telefone values (telefone, id);");
		if (!res) printf("TELEFONE ADICIONADO COM SUCESSO %d\n");
		else printf("ERRO AO CRIAR CONTATO %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
	}
	
	//adiciona um email ao contato informado
	void adiciona_email(int id, char[] email){
		res = mysql_query(&conexao,"insert into programac_telefone values (email, id);");
		if (!res) printf("EMAIL ADICIONADO COM SUCESSO %d\n");
		else printf("ERRO AO CRIAR CONTATO %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
	}
	
	//busca o contato pelo nome e retorna o id
	int retorna_contato_id(char[] nome){
		if (mysql_query(&conexao,"select codigo from programac_agenda where nome like '%s';", nome))
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
		if (mysql_query(&conexao, "select * from programac_agenda a inner join programac_telefone t inner join programac_email e on a.codigo=t.codigo and a.codigo=e.codigo and a.codigo=%d;", codigo))
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
		if (mysql_query(&conexao, "select * from programac_agenda a inner join programac_telefone t inner join programac_email e on a.codigo=t.codigo and a.codigo=e.codigo and a.nome like '%s';", nome))
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
		if (mysql_query(&conexao, "select * from programac_agenda a inner join programac_telefone t inner join programac_email e on a.codigo=t.codigo and a.codigo=e.codigo and t.telefone=%d;", telefone))
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
		if (mysql_query(&conexao, "select * from programac_agenda a inner join programac_telefone t inner join programac_email e on a.codigo=t.codigo and a.codigo=e.codigo and e.email like '%s';", email))
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
	
	//excluir o contato pelo nome
	void exclui_contato_nome (char[] nome){
		res=mysql_query(&conexao,"delete from programac_agenda where nome like '%s'", nome);
	    if (!res) printf("SUCESSO NA EXCLUSÃO %d\n");
	    else printf("ERRO NA EXCLUSÃO %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));     
		
	}
	 
}
