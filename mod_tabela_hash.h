/**
 * @file mod_tabela_hash.h
 * @brief Módulo de tabela de Hash
 * @details O módulo de tabela de hash, com todas as estruturas e funções genéricas
 * */
#ifndef MOD_TABELA_HASH_H_INCLUDED
#define MOD_TABELA_HASH_H_INCLUDED

#include "mod_lista_ligada.h"

/**
	@brief Tabela de Hash com chaining
	@details Tabela de Hash com elementos encadeados com listas ligadas
	@param arraycell Array de apontadores para uma lista ligada
	@param hash_function Função de hash para dispersão dos elementos pela tabela
	@param nelems Número de elementos inseridos na tabela
	@param totalcells Número de elementos da tabela
 */
typedef struct TabelaHash{
	MainListPTR *arraycell;
	int (*hash_function)(void*,int);
	int nelems;
	int totalcells;
}*TabelaHashPTR;



/**
	@brief Cria a tabela de hash e inicia as listas ligadas a NULL
	@param hash_function Função de hash para dispersão de elementos
	@param startcells Numero de elementos iniciais da tabela
        @param func_compare Apontador para a função de comparação
	@return Apontador para tabela de hash
 */
TabelaHashPTR criaTabelaHash (int(*hash_function)(void*,int), int startcells, int (*func_compare)(void*,void*));



/**
	@brief Verifica o factor de ocupação da tabela de hash 
	@param table Apontador para a tabela de hash
	@return 0 se está com um factor de ocupação maior que o indicado
	@return 1 se não está com um factor de ocupação maior que o indicado
 */
int ocupacaoTabelaHash (TabelaHashPTR table);



/**
	@brief Aloca mais espaço para a tabela de hash caso esta tenha ultrapassado o factor de ocupação indicado
	@param table Apontador para a tabela de hash
	@return 0 se não conseguiu alocar espaço suficiente
	@return 1 se alocou com sucesso
 */
int aumentaTabelaHash (TabelaHashPTR table);



/**
	@brief Diminui o espaço alocado para a tabela de hash caso esta tenha ultrapassado o factor de ocupação indicado
	@param table Apontador para a tabela de hash
	@return 0 se não conseguiu alocar espaço suficiente
	@return 1 se alocou com sucesso
 */
int diminuiTabelaHash (TabelaHashPTR table);



/**
	@brief Insere um elemento na tabela de hash
	@param table Apontador para a tabela de hash
	@param externdata Apontador para o elemento a inserir
	@return 0 se não conseguiu inserir
	@return 1 se inseriu com sucesso
 */
int insereElementoTabelaHash (TabelaHashPTR table, void *externdata);



/**
	@brief Procura um elemento na tabela de hash
	@param table Apontador para a tabela de hash
	@param externdata Apontador para o elemento a procurar
	@return Apontador para o elemento encontrado ou NULL
 */
LinkedListPTR procuraTabelaHash (TabelaHashPTR table, void *externdata);


void aplicaFuncTabelaHash(TabelaHashPTR table, void (*applyFunction)(void *, void *), void *parametros) ;

/**
	@brief Elimina um elemento dado da tabela de hash
	@param table Apontador para a tabela de hash
	@param externdata Apontador para o elemento a elimiar
	@return 1 se pagado
	@return 0 se não apagado/encontrado
 */
int apagaElementoTabelaHash (TabelaHashPTR table, void* externdata);



/**
	@brief Elimina todos os elementos da tabela de hash
	@param table Apontador para a tabela de hash
 */
void apagaTabelaHash(TabelaHashPTR table);



/*
	@brief Indica o indice na tabela onde um elemento será inserido/procurado/eliminado
	@param a Apontador para os dados a analisar e criar hashkey
	@param b Numero de elementos total da tabela
 */
//int hash_function(void*a,int b);

#endif /* MOD_TABELA_HASH_H_INCLUDED */
