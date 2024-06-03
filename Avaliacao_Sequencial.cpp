#include <iostream>
#include <conio.h>
#include <string.h>
#include <locale.h>
using namespace std;

struct cidade{
	int codCid;
	char nomeCid[30];
	char uf[2];
};

struct curso{
	int codCurs;
	char descCurs[30];
	float valorAula;
};

struct instrutor{
	int codInst;
	char nomeInst[30];
	char ender[30];
	int codCid;
};

struct aluno{
	int codAlu;
	char nomeAlu[30];
	char ender[30];
	int codCid;
};

struct turma{
	int codTur;
	int codCurs;
	int codInst;
	int totPartic;
	int maxPartic;
};

struct matricula{
	int codMatri;
	int codAlu;
	int codTur;
	int quantAulas;
	float valTot;
};

void lerCid(cidade ca[], int &cont);
int checCodCid(cidade ca[], int numchecCid, int novoCodCid);

void lerInst(instrutor ca[], int &cont, cidade structcidade[], int numeroCidCad);
void lerAddInst(
	instrutor ca[], 
	int &cont, 
	instrutor instOrig[],
	int NumeroInstCad, 
	cidade structcidade[], 
	int numeroCidCad
);
int checCodInst(instrutor ca[], int numchecInst, int novoCodInst);
void inclusaoInst(
	instrutor original[], 
	int contOri, 
	instrutor novo[], 
	int contN, 
	instrutor addInst[], 
	int &contAdd
);
int checInstValid(instrutor ca[], int numchecInst, int checCodInst, cidade cb[], int numchecCid);

void lerCurs(curso ca[], int &cont);

void lerTur(
	turma ca[], 
	int &cont, 
	curso cursOrig[], 
	int numeroCursCad, 
	instrutor instOrig[], 
	int numeroInstCad,
	cidade cidadeOrig[], 
	int numchecCid
);
void lerAddTur(
	turma ca[], 
	int &cont,
	turma turmOrig[],
	int numeroTurmCad,
	curso cursOrig[],
	int numeroCursCad, 
	instrutor instOrig[], 
	int numeroInstCad,
	cidade cidadeOrig[], 
	int numchecCid
);
int checCodTur(turma ca[], int numchecTur, int novoCodTur);
void inclusaoTurma(turma original[], int contOri, turma novo[], int contN, turma addTur[], int &contAdd);

void lerAlu(aluno ca[], int &cont, cidade structcidade[], int numeroCidCad);
void lerAddAlu(
	aluno ca[], 
	int &cont, 
	aluno aluOrig[],
	int NumeroAluCad, 
	cidade structcidade[], 
	int numeroCidCad
);
int checCodAlu(aluno ca[], int numchecAlu, int novoCodAlu);
void inclusaoAlu(aluno original[], int contOri, aluno novo[], int contN, aluno addAlu[], int &contAdd);
void lerAluParaExclu(aluno ca[], int &cont);
void exclusaoAlu(aluno original[], int contOri, aluno paraExclu[], int contPx, aluno finalAlu[], int &contFim);
int checAluValid(aluno ca[], int numChecAlu, int checCodAlu, cidade cb[], int numchecCid);

void lerMatri(
	matricula ca[], 
	int &cont,
	aluno aluOrig[],
	int numeroAluCad,
	cidade cidadeOrig[],
	int numchecCid,
	turma turmaOrig[], 
	int numeroTurCad,
	curso cursOrig[], 
	int numeroCursCad,
	instrutor instOrig[], 
	int numeroInstCad
);
void lerAddMatri(
	matricula ca[], 
	int &cont,
	matricula matriOrig[],
	int numeroMatriCad,
	aluno aluOrig[],
	int numeroAluCad,
	cidade cidadeOrig[],
	int numchecCid,
	turma turmaOrig[], 
	int numeroTurCad,
	curso cursOrig[], 
	int numeroCursCad,
	instrutor instOrig[], 
	int numeroInstCad
);
int checCodMatri(matricula ca[], int numChecMatri, int novoCodMatri);
void inclusaoMatri(
	matricula original[], 
	int contOri, 
	matricula novo[], 
	int contN, 
	matricula addMatri[], 
	int &contAdd
);


int main(){
	setlocale(LC_ALL, "Portuguese");  
	//Variaveis
	int tipoCadastro = 0;
	int checkCidade = 0;
	int checkCurso = 0;
	int checkInstrutor = 0;
	int checkAluno = 0;
	int checkTur = 0;
	int checkMatri = 0;
	
	//Contadores
	int contCi = 0;
	int contCurs = 0;
	
	int contInst = 0;
	int contNovoInst = 0;
	int contAddInst = 0;
	
	int contAlu = 0;
	int contNovoAlu = 0;
	int contAddAlu = 0;
	
	int contTur = 0;
	int contNovaTur = 0;
	int contAddTur = 0;
	
	int contMatri = 0;
	int contNovaMatri = 0;
	int contAddMatri = 0;
	
	//Estruturas
	cidade cidadeAtual[20];
	
	instrutor instruAtual[20];
	instrutor novoInst[20];
	instrutor adicaoInst[40];
	
	curso cursoAtual[20];
	
	aluno alunoAtual[20];
	aluno novoAlu[20];
	aluno adicaoAlu[40];
	
	turma turmaAtual[20];
	turma novaTurma[20];
	turma adicaoTurma[40];
	
	matricula matriAtual[20];
	matricula novaMatri[20];
	matricula adicaoMatri[40];
	
	do{
		cout << "Informe o número para selecionar o cadastro, escolha -1 para finalizar o programa:";
		cout << "\n0 - Cidade"; 
		cout << "\n1 - Curso"; 
		cout << "\n2 - Instrutor"; 
		cout << "\n3 - Aluno"; 
		cout << "\n4 - Turma"; 
		cout << "\n5 - Matrícula";
		cout << "\n6 - Novos Registros para Instrutor:";
		cout << "\n7 - Novos Registros/Excluir Registros para Aluno:\n";
		cin >> tipoCadastro;
		
		while(tipoCadastro > 7){
			cout << "\nNúmero inserido inválido! Insira um número de 0 a 6:\n";
			cin >> tipoCadastro;
		}
		
		switch(tipoCadastro){
			// Case para Cidade
			case 0:
				lerCid(cidadeAtual, contCi);
				checkCidade = 1;
			break;
			
			// Case para Curso
			case 1:
				lerCurs(cursoAtual, contCurs);
				checkCurso = 1;
			break;
			
			// Case para Instrutor
			case 2:
				if(checkCidade == 0){
					cout << "Não é possível cadastrar Instrutores sem houver Cidades cadastradas.\n";
					break;
				} else {
					lerInst(instruAtual, contInst, cidadeAtual, contCi);
					checkInstrutor = 1;
					break;
				}	
			
			// Case para Aluno
			case 3:
				if(checkCidade == 0){
					cout << "Não é possível cadastrar Instrutores sem haver Cidades cadastradas.\n";
					break;
				} else {
					lerAlu(alunoAtual, contAlu, cidadeAtual, contCi);
					checkAluno = 1;
					break;
				}	
				
			break;
			
			// Case para Turma
			case 4:
				if(checkInstrutor == 0){
					cout << "Não é possível cadastrar Turmas sem haver Instrutores já cadastrados.\n";
					break;
				} else if(checkCurso == 0){
					cout << "Não é possível cadastrar Turmas sem haver Cursos já cadastrados.\n";
					break;
				} else if(checkInstrutor == 1){
					lerTur(
						turmaAtual, 
						contTur, 
						cursoAtual, 
						contCurs, 
						instruAtual, 
						contInst, 
						cidadeAtual, 
						contCi
					);
					checkTur = 1;
					break;
				} else {
					lerTur(
						turmaAtual, 
						contTur, 
						cursoAtual, 
						contCurs, 
						adicaoInst,
						contAddInst,
						cidadeAtual, 
						contCi
					);
					checkTur = 1;
					break;
				}
			break;
				
			
			// Case para Matrícula
			case 5:
				if(checkTur == 0){
					cout << "Não é possível cadastrar Matrículas sem haver Turmas já cadastradas.\n";
					break;
				} else if(checkAluno == 0){
					cout << "Não é possível cadastrar Matrículas sem haver Alunos já cadastrados.\n";
					break;
				} else if(checkTur == 1){
					if(checkAluno == 1){
						if(checkInstrutor == 1){
							lerMatri(
								matriAtual, 
								contMatri,
								alunoAtual, 
								contAlu, 
								cidadeAtual, 
								contCi,
								turmaAtual, 
								contTur,
								cursoAtual, 
								contCurs,
								instruAtual, 
								contInst
							);
							checkMatri = 1;
							break;
						} else {
							lerMatri(
								matriAtual, 
								contMatri,
								alunoAtual, 
								contAlu, 
								cidadeAtual, 
								contCi,
								turmaAtual, 
								contTur,
								cursoAtual, 
								contCurs,
								adicaoInst, 
								contAddInst
							);
							checkMatri = 1;
							break;
						}
					} else {
						if(checkInstrutor == 1){
							lerMatri(
								matriAtual, 
								contMatri,
								adicaoAlu, 
								contAddAlu, 
								cidadeAtual, 
								contCi,
								turmaAtual, 
								contTur,
								cursoAtual, 
								contCurs,
								instruAtual, 
								contInst
							);
							checkMatri = 1;
							break;
						} else {
							lerMatri(
								matriAtual, 
								contMatri,
								adicaoAlu, 
								contAddAlu,
								cidadeAtual, 
								contCi,
								turmaAtual, 
								contTur,
								cursoAtual, 
								contCurs,
								adicaoInst, 
								contAddInst
							);
							checkMatri = 1;
							break;
						}
					}	
				} else {
					if(checkAluno == 1){
						if(checkInstrutor == 1){
							lerMatri(
								matriAtual, 
								contMatri,
								alunoAtual, 
								contAlu, 
								cidadeAtual, 
								contCi,
								adicaoTurma,
								contAddTur,
								cursoAtual, 
								contCurs,
								instruAtual, 
								contInst
							);
							checkMatri = 1;
							break;
						} else {
							lerMatri(
								matriAtual, 
								contMatri,
								alunoAtual, 
								contAlu, 
								cidadeAtual, 
								contCi,
								adicaoTurma,
								contAddTur,
								cursoAtual, 
								contCurs,
								adicaoInst, 
								contAddInst
							);
							checkMatri = 1;
							break;
						}
					} else {
						if(checkInstrutor == 1){
							lerMatri(
								matriAtual, 
								contMatri,
								adicaoAlu, 
								contAddAlu, 
								cidadeAtual, 
								contCi,
								adicaoTurma,
								contAddTur,
								cursoAtual, 
								contCurs,
								instruAtual, 
								contInst
							);
							checkMatri = 1;
							break;
						} else {
							lerMatri(
								matriAtual, 
								contMatri,
								adicaoAlu, 
								contAddAlu,
								cidadeAtual, 
								contCi,
								adicaoTurma,
								contAddTur,
								cursoAtual, 
								contCurs,
								adicaoInst, 
								contAddInst
							);
							checkMatri = 1;
							break;
						}
					}
				}
			break;
			
			// Case para Instrutor Extra
			case 6:
				if(checkInstrutor == 0){
					cout << "Não é possível cadastrar novos Instrutores sem haver Instrutores já cadastrados.\n";
					break;
				} else {
					lerAddInst(novoInst, contNovoInst, instruAtual, contInst, cidadeAtual, contCi);
					inclusaoInst(instruAtual, contInst, novoInst, contNovoInst,  adicaoInst, contAddInst);
					checkInstrutor = 2;
					break;
				}	
			break;
			
			// Case para Aluno Extra
			case 7:
				if(checkAluno == 0){
					cout << "Não é possível cadastrar novos Alunos sem haver Alunos já cadastrados.\n";
					break;
				} else {
					int selectAcao = 0;
					cout << "Deseja adicionar novos registros em Alunos ou Excluir alunos?\n";
					cout << "1 - Adicionar registros em Aluno\n";
					cout << "2 - Excluir registros em Aluno\n";
					cin >> selectAcao;
					if(selectAcao == 1){
						lerAddAlu(novoAlu, contNovoAlu, alunoAtual, contAlu, cidadeAtual, contCi);
						inclusaoAlu(alunoAtual, contAlu, novoAlu, contNovoAlu,  adicaoAlu, contAddAlu);
						break;
					} else if(selectAcao == 2){
						lerAluParaExclu(novoAlu, contNovoAlu);
						break;
					} else {
						cout << "Número inválido inserido.\n";
						break;
					}		
				}	
			break;
			
			//Case para Turma extra
			case 8:
				if(checkTur == 0){
					cout << "Não é possível cadastrar novas Turmas sem haver Turmas já cadastradas.\n";
					break;
				} else if(checkInstrutor == 1){
					lerAddTur(
						novaTurma,
						contNovaTur,
						turmaAtual, 
						contTur,
						cursoAtual, 
						contCurs, 
						instruAtual, 
						contInst, 
						cidadeAtual, 
						contCi
					);
					inclusaoTurma(
						turmaAtual, 
						contTur,
						novaTurma,
						contNovaTur,
						adicaoTurma,
						contAddTur
					);
					checkTur = 2;
					break;
				} else {
					lerAddTur(
						novaTurma,
						contNovaTur,
						turmaAtual, 
						contTur,
						cursoAtual, 
						contCurs, 
						adicaoInst,
						contAddInst,
						cidadeAtual, 
						contCi
					);
					inclusaoTurma(
						turmaAtual, 
						contTur,
						novaTurma,
						contNovaTur,
						adicaoTurma,
						contAddTur
					);
					checkTur = 2;
					break;
				}
			break;
			
			//Case para Matrícula Extra
			case: 9
				if(checkMatri == 0){
					cout << "Não é possível cadastrar novas Matrículas sem haver Matrículas já cadastradas.\n";
					break;
				} else if(checkTur == 1){
					if(checkAluno == 1){
						if(checkInstrutor == 1){
							lerAddMatri(
								novaMatri,
								contNovaMatri,
								matriAtual, 
								contMatri,
								alunoAtual, 
								contAlu, 
								cidadeAtual, 
								contCi,
								turmaAtual, 
								contTur,
								cursoAtual, 
								contCurs,
								instruAtual, 
								contInst
							);
							inclusaoMatri(
								matriAtual, 
								contMatri, 
								novaMatri,
								contNovaMatri, 
								adicaoMatri, 
								int &contAdd
							);
							checkMatri = 2;
							break;
						} else {
							lerAddMatri(
								novaMatri,
								contNovaMatri,
								matriAtual, 
								contMatri,
								alunoAtual, 
								contAlu, 
								cidadeAtual, 
								contCi,
								turmaAtual, 
								contTur,
								cursoAtual, 
								contCurs,
								adicaoInst, 
								contAddInst
							);
							checkMatri = 2;
							break;
						}
					} else {
						if(checkInstrutor == 1){
							lerAddMatri(
								novaMatri,
								contNovaMatri,
								matriAtual, 
								contMatri,
								adicaoAlu, 
								contAddAlu, 
								cidadeAtual, 
								contCi,
								turmaAtual, 
								contTur,
								cursoAtual, 
								contCurs,
								instruAtual, 
								contInst
							);
							checkMatri = 2;
							break;
						} else {
							lerAddMatri(
								novaMatri,
								contNovaMatri,
								matriAtual, 
								contMatri,
								adicaoAlu, 
								contAddAlu,
								cidadeAtual, 
								contCi,
								turmaAtual, 
								contTur,
								cursoAtual, 
								contCurs,
								adicaoInst, 
								contAddInst
							);
							checkMatri = 2;
							break;
						}
					}	
				} else {
					if(checkAluno == 1){
						if(checkInstrutor == 1){
							lerAddMatri(
								novaMatri,
								contNovaMatri,
								matriAtual, 
								contMatri,
								alunoAtual, 
								contAlu, 
								cidadeAtual, 
								contCi,
								adicaoTurma,
								contAddTur,
								cursoAtual, 
								contCurs,
								instruAtual, 
								contInst
							);
							checkMatri = 2;
							break;
						} else {
							lerAddMatri(
								novaMatri,
								contNovaMatri,
								matriAtual, 
								contMatri,
								alunoAtual, 
								contAlu, 
								cidadeAtual, 
								contCi,
								adicaoTurma,
								contAddTur,
								cursoAtual, 
								contCurs,
								adicaoInst, 
								contAddInst
							);
							checkMatri = 2;
							break;
						}
					} else {
						if(checkInstrutor == 1){
							lerAddMatri(
								novaMatri,
								contNovaMatri,
								matriAtual, 
								contMatri,
								adicaoAlu, 
								contAddAlu, 
								cidadeAtual, 
								contCi,
								adicaoTurma,
								contAddTur,
								cursoAtual, 
								contCurs,
								instruAtual, 
								contInst
							);
							checkMatri = 2;
							break;
						} else {
							lerAddMatri(
								novaMatri,
								contNovaMatri,
								matriAtual, 
								contMatri,
								adicaoAlu, 
								contAddAlu,
								cidadeAtual, 
								contCi,
								adicaoTurma,
								contAddTur,
								cursoAtual, 
								contCurs,
								adicaoInst, 
								contAddInst
							);
							checkMatri = 2;
							break;
						}
					}
				}
			break;
		}
	} while(tipoCadastro != -1);
}

//Funções relacionadas a struct Cidade -------------------------

void lerCid(cidade ca[], int &cont){
	int numCid = 0;
	cout << "Cadastro de Cidade: \n";
	cout << "Informe o número de Cidades que deseja Cadastrar: \n";
	cin >> numCid;
	for(int i = 0; i < numCid; i++){
		cout << "\nInforme o Código da Cidade: \n";
		cin >> ca[i].codCid;
		cout << "Informe o Nome da Cidade: \n";
		cin >> ca[i].nomeCid;
		cout << "Informe o Estado onde a Cidade: \n";
		cin >> ca[i].uf;
		cont++;
	}
}

int checCodCid(cidade ca[], int numchecCid, int novoCodCid){
	int inicio = 0;
	int fim = numchecCid - 1;
	int m = (inicio + fim) / 2;
	
	for (; fim >= inicio && novoCodCid != ca[m].codCid; m = (inicio + fim) / 2){
        if (novoCodCid > ca[m].codCid)
            inicio = m + 1;
        else
            fim = m - 1;
    }
    if (novoCodCid == ca[m].codCid){
    	cout << "\nCidade Encontrada!";
        cout << "\nNome da Cidade cujo código pertence: " << ca[m].nomeCid << ".";
        cout << "\nUF da Cidade cujo código pertence: " << ca[m].uf << ".\n";
        return 1;
    } else {
    	cout << "\nCidade não encontrada, tente novamente.\n";
    	return -1;
	}
}

// Fundções Relacionadas a struct Curso -------------------------

void lerCurs(curso ca[], int &cont){
	cout << "Cadastro de Curso: \n";
	for(int i = 0; i < cont; i++){
		cout << "\nInforme o Código do Curso: \n";
		cin >> ca[i].codCurs;
		cout << "Informe a descrição do Curso: \n";
		cin >> ca[i].descCurs;
		cout << "Informe o Valor por Aula: \n";
		cin >> ca[i].valorAula;
	}
}

int checCodCurs(curso ca[], int numchecCurs, int novoCodCurs){
	int inicio = 0;
	int fim = numchecCurs - 1;
	int m = (inicio + fim) / 2;
	
	for (; fim >= inicio && novoCodCurs != ca[m].codCurs; m = (inicio + fim) / 2){
        if (novoCodCurs > ca[m].codCurs)
            inicio = m + 1;
        else
            fim = m - 1;
    }
    if (novoCodCurs == ca[m].codCurs){
    	cout << "\nCurso Encontrado!";
        cout << "\nDescrição do Curso cujo código pertence: " << ca[m].descCurs << ".";
        cout << "\nValor do Curso cujo código pertence: " << ca[m].valorAula << ".\n";
        return 1;
    } else {
    	cout << "\nCurso não encontrado, tente novamente.\n";
    	return -1;
	}
}

// Funções Relacionadas a struct Instrutor -------------------------
// Ler instrutor
void lerInst(instrutor ca[], int &cont, cidade structcidade[], int numeroCidCad){
	cont = 0;
	int numInst = 0;
	cout << "Cadastro de Instrutor:\n";
	cout << "Informe o número de Instrutores que deseja Cadastrar:\n";
	cin >> numInst;
	for(int i = 0; i < numInst; i++){
		cout << "\nInforme o Código do Instrutor: \n";
		cin >> ca[i].codInst;
		cout << "Informe o Nome do Instrutor: \n";
		cin >> ca[i].nomeInst;
		cout << "Informe o Endereço do Instrutor: \n";
		cin >> ca[i].ender;
		cout << "Informe o Código da Cidade: \n";
		cin >> ca[i].codCid;
		while(checCodCid(structcidade, numeroCidCad, ca[i].codCid) == -1){
			cout << "\nO Código Informado é inválido! Tente Novamente! \n";
			cin >> ca[i].codCid;
		}
		cont++;
	}
}

//Ler instrutor adicional
void lerAddInst(
	instrutor ca[],
	int &cont,
	instrutor instOrig[],
	int NumeroInstCad,
	cidade structcidade[],
	int numeroCidCad
	){
		cont = 0;
		int numInst = 0;
		cout << "Adição de Registro em Instrutor:\n";
		cout << "Informe o número de Instrutores que deseja Cadastrar:\n";
		cin >> numInst;
		for(int i = 0; i < numInst; i++){
			cout << "\nInforme o Código do Instrutor: \n";
			cin >> ca[i].codInst;
			while(checCodInst(instOrig, NumeroInstCad, ca[i].codInst) == -1){
				cout << "\nO Código Informado é inválido! Tente Novamente! \n";
				cin >> ca[i].codInst;
			}
			cout << "Informe o Nome do Instrutor: \n";
			cin >> ca[i].nomeInst;
			cout << "Informe o Endereço do Instrutor: \n";
			cin >> ca[i].ender;
			cout << "Informe o Código da Cidade: \n";
			cin >> ca[i].codCid;
			while(checCodCid(structcidade, numeroCidCad, ca[i].codCid) == -1){
				cout << "\nO Código Informado é inválido! Tente Novamente! \n";
				cin >> ca[i].codCid;
			}
			cont++;
		}
	}

//Checagem do Código de Instrutor
int checCodInst(instrutor ca[], int numchecInst, int novoCodInst){
	int inicio = 0;
	int fim = numchecInst - 1;
	int m = (inicio + fim) / 2;
	
	for (; fim >= inicio && novoCodInst != ca[m].codInst; m = (inicio + fim) / 2){
        if (novoCodInst > ca[m].codInst)
            inicio = m + 1;
        else
            fim = m - 1;
    }
    if (novoCodInst == ca[m].codInst){
    	cout << "\nInstrutor encontrado! Insira um novo código!";
        return -1;
    } else {
    	cout << "\nInstrutor não encontrado, código válido.";
    	return 1;
	}
}

//Validação de Instrutor
int checInstValid(instrutor ca[], int numchecInst, int checCodInst, cidade cb[], int numchecCid){
	int inicio = 0;
	int fim = numchecInst - 1;
	int m = (inicio + fim) / 2;
	
	for (; fim >= inicio && checCodInst != ca[m].codInst; m = (inicio + fim) / 2){
        if (checCodInst > ca[m].codInst)
            inicio = m + 1;
        else
            fim = m - 1;
    }
    if (checCodInst == ca[m].codInst){
    	int i;
    	inicio = 0;
		fim = numchecCid - 1;
		i = (inicio + fim) / 2;
	
		for(; fim >= inicio && cb[i].codCid != ca[m].codCid; i = (inicio + fim) / 2){
        	if(cb[i].codCid > ca[m].codCid){
        		inicio = m + 1;
			} else {
				fim = m - 1;
			}	
    	}
    	cout << "\nInstrutor encontrado!";
    	cout << "\nNome do Instrutor: " << ca[m].nomeInst << ".";
        cout << "\nNome da Cidade cujo instrutor mora: " << cb[i].nomeCid << ".\n";
        return 1;
    } else {
    	cout << "\nInstrutor não encontrado, código inválido.";
    	return -1;
	}
}

//Função de Inclusão
void inclusaoInst(instrutor original[], int contOri, instrutor novo[], int contN, instrutor addInst[], int &contAdd){
	int Ori = 0, Nov = 0, Add = 0;
    for (;Ori < contOri && Nov < contN; Add++){
        if (original[Ori].codInst < novo[Nov].codInst){
            addInst[Add].codInst = original[Ori].codInst;
            strcpy (addInst[Add].nomeInst,original[Ori].nomeInst);
            strcpy (addInst[Add].ender,original[Ori].ender);
            addInst[Add].codCid = original[Ori].codCid;
            Ori++;
            }
        else {
            addInst[Add].codInst = novo[Nov].codInst;
            strcpy (addInst[Add].nomeInst,novo[Nov].nomeInst);
            strcpy (addInst[Add].ender,novo[Nov].ender);
            addInst[Add].codCid = novo[Nov].codCid;
            Nov++;
        }
    }
    while (Ori < contOri){
        addInst[Add].codInst = original[Ori].codInst;
        strcpy (addInst[Add].nomeInst,original[Ori].nomeInst);
        strcpy (addInst[Add].ender,original[Ori].ender);
        addInst[Add].codCid = original[Ori].codCid;
        Ori++;
        Add++;
    }
    while (Nov < contN){
        addInst[Add].codInst = novo[Nov].codInst;
        strcpy (addInst[Add].nomeInst, novo[Nov].nomeInst);
        strcpy (addInst[Add].ender, novo[Nov].ender);	
        addInst[Add].codCid = novo[Nov].codCid;
        Nov++;
        Add++;
    }
    contAdd = Add;
}

// Funções Relacionadas a struct Aluno ------------------------------------------------------------------

void lerAlu(aluno ca[], int &cont, cidade structcidade[], int numeroCidCad){
	cont = 0;
	int numAlu = 0;
	cout << "Cadastro de Aluno:\n";
	cout << "Informe o número de Alunos que deseja Cadastrar:\n";
	cin >> numAlu;
	for(int i = 0; i < numAlu; i++){
		cout << "\nInforme o Código do Aluno: \n";
		cin >> ca[i].codAlu;
		cout << "Informe o Nome do Aluno: \n";
		cin >> ca[i].nomeAlu;
		cout << "Informe o Endereço do Aluno: \n";
		cin >> ca[i].ender;
		cout << "Informe o Código da Cidade: \n";
		cin >> ca[i].codCid;
		while(checCodCid(structcidade, numeroCidCad, ca[i].codCid) == -1){
			cout << "\nO Código Informado é inválido! Tente Novamente! \n";
			cin >> ca[i].codCid;
		}
		cont++;
	}
}

//Leitura de Alunos a adicionar
void lerAddAlu(
		aluno ca[], 
		int &cont, 
		aluno aluOrig[],
		int NumeroAluCad, 
		cidade structcidade[], 
		int numeroCidCad
	){
		cont = 0;
		int numAlu = 0;
		cout << "Adição de Registro em Aluno:\n";
		cout << "Informe o número de Alunos que deseja Cadastrar:\n";
		cin >> numAlu;
		for(int i = 0; i < numAlu; i++){
			cout << "\nInforme o Código do Aluno: \n";
			cin >> ca[i].codAlu;
			while(checCodAlu(aluOrig, NumeroAluCad, ca[i].codAlu) == -1){
				cout << "\nO Código Informado é inválido! Tente Novamente! \n";
				cin >> ca[i].codAlu;
			}
			cout << "Informe o Nome do Aluno: \n";
			cin >> ca[i].nomeAlu;
			cout << "Informe o Endereço do Aluno: \n";
			cin >> ca[i].ender;
			cout << "Informe o Código da Cidade: \n";
			cin >> ca[i].codCid;
			while(checCodCid(structcidade, numeroCidCad, ca[i].codCid) == -1){
				cout << "\nO Código Informado é inválido! Tente Novamente! \n";
				cin >> ca[i].codCid;
			}
			cont++;
		}
}

//Alunos a serem excluidos
void lerAluParaExclu(aluno ca[], int &cont){
	cont = 0;
	int numAlu = 0;
	cout << "Exclusão de Registro em Aluno:\n";
	cout << "Informe o número de Alunos que deseja Excluir:\n";
	cin >> numAlu;
	for(int i = 0; i < numAlu; i++){
		cout << "\nInforme o Código do Aluno: \n";
		cin >> ca[i].codAlu;
		cont++;
	}
}

//Checar código de Aluno
int checCodAlu(aluno ca[], int numchecAlu, int novoCodAlu){
	int inicio = 0;
	int fim = numchecAlu - 1;
	int m = (inicio + fim) / 2;
	
	for (; fim >= inicio && novoCodAlu != ca[m].codAlu; m = (inicio + fim) / 2){
        if (novoCodAlu > ca[m].codAlu)
            inicio = m + 1;
        else
            fim = m - 1;
    }
    if (novoCodAlu == ca[m].codAlu){
    	cout << "\nAluno encontrado! Insira um novo código!";
        return -1;
    } else {
    	cout << "\nAluno não encontrado, código válido.";
    	return 1;
	}
}

//Busca em Aluno
int checAluValid(aluno ca[], int numChecAlu, int checCodAlu, cidade cb[], int numchecCid){
	int inicio = 0;
	int fim = numChecAlu - 1;
	int m = (inicio + fim) / 2;
	
	for (; fim >= inicio && checCodAlu != ca[m].codAlu; m = (inicio + fim) / 2){
        if (checCodAlu > ca[m].codAlu)
            inicio = m + 1;
        else
            fim = m - 1;
    }
    if (checCodAlu == ca[m].codAlu){
    	int i;
    	inicio = 0;
		fim = numChecAlu - 1;
		i = (inicio + fim) / 2;
	
		for(; fim >= inicio && cb[i].codCid != ca[m].codCid; i = (inicio + fim) / 2){
        	if(cb[i].codCid > ca[m].codCid){
        		inicio = i + 1;
			} else {
				fim = i - 1;
			}	
    	}
    	cout << "\nAluno encontrado!";
    	cout << "\nNome do Aluno: " << ca[m].nomeAlu << ".";
        cout << "\nNome da Cidade cujo aluno mora: " << cb[i].nomeCid << ".\n";
        return 1;
    } else {
    	cout << "\nAluno não encontrado, código inválido.";
    	return -1;
	}
}

// Inclusão de ALuno
void inclusaoAlu(aluno original[], int contOri, aluno novo[], int contN, aluno addAlu[], int &contAdd){
	int Ori = 0, Nov = 0, Add = 0;
    for (;Ori < contOri && Nov < contN; Add++){
        if (original[Ori].codAlu < novo[Nov].codAlu){
            addAlu[Add].codAlu = original[Ori].codAlu;
            strcpy (addAlu[Add].nomeAlu,original[Ori].nomeAlu);
            strcpy (addAlu[Add].ender,original[Ori].ender);
            addAlu[Add].codCid = original[Ori].codCid;
            Ori++;
            }
        else {
            addAlu[Add].codAlu = novo[Nov].codAlu;
            strcpy (addAlu[Add].nomeAlu,novo[Nov].nomeAlu);
            strcpy (addAlu[Add].ender,novo[Nov].ender);
            addAlu[Add].codCid = novo[Nov].codCid;
            Nov++;
        }
    }
    while (Ori < contOri){
        addAlu[Add].codAlu = original[Ori].codAlu;
        strcpy (addAlu[Add].nomeAlu,original[Ori].nomeAlu);
        strcpy (addAlu[Add].ender,original[Ori].ender);
        addAlu[Add].codCid = original[Ori].codCid;
        Ori++;
        Add++;
    }
    while (Nov < contN){
        addAlu[Add].codAlu = novo[Nov].codAlu;
        strcpy (addAlu[Add].nomeAlu, novo[Nov].nomeAlu);
        strcpy (addAlu[Add].ender, novo[Nov].ender);	
        addAlu[Add].codCid = novo[Nov].codCid;
        Nov++;
        Add++;
    }
    contAdd = Add;
}

void exclusaoAlu(aluno original[], int contOri, aluno paraExclu[], int contPx, aluno finalAlu[], int &contFim){
    int Ori = 0, Exclu = 0, Fim = 0; // i (contador de S) j (contador de T) k (contador de A)
    for (;Exclu < contPx; Ori++){
        if (original[Ori].codAlu != paraExclu[Exclu].codAlu){
            finalAlu[Fim].codAlu = original[Ori].codAlu;
            strcpy (finalAlu[Fim].nomeAlu,original[Ori].nomeAlu);
            strcpy (finalAlu[Fim].ender,original[Ori].ender);
            finalAlu[Fim].codCid = original[Ori].codCid;
            Fim++;
            }
        else {
            Exclu++;
        }
    }
    while (Ori < contOri){
        finalAlu[Fim].codAlu = original[Ori].codAlu;
        strcpy (finalAlu[Fim].nomeAlu,original[Ori].nomeAlu);
        strcpy (finalAlu[Fim].ender,original[Ori].ender);
        finalAlu[Fim].codCid = original[Ori].codCid;
        Ori++;
        Fim++;
    }
    contFim = Fim;
}


// Funções Relacionadas a struct Turma ------------------------------------------------------------------

//Leitura de Turma
void lerTur(
	turma ca[], 
	int &cont, 
	curso cursOrig[], 
	int numeroCursCad, 
	instrutor instOrig[], 
	int numeroInstCad,
	cidade cidadeOrig[], 
	int numchecCid
){
	cont = 0;
	int numTur = 0;
	cout << "Cadastro de Turma:\n";
	cout << "Informe o número de Alunos que deseja Cadastrar:\n";
	cin >> numTur;
	for(int i = 0; i < numTur; i++){
		cout << "\nInforme o Código da Turma: \n";
		cin >> ca[i].codTur;
		cout << "Informe o Nome do Curso a qual ela pertence: \n";
		cin >> ca[i].codCurs;
		while(checCodCurs(cursOrig, numeroCursCad, ca[i].codCurs) == -1){
			cout << "\nO Código Informado é inválido! Tente Novamente! \n";
			cin >> ca[i].codCurs;
		}
		cout << "Informe o Código do Instrutor: \n";
		cin >> ca[i].codInst;
		while(checInstValid(instOrig, numeroInstCad, ca[i].codInst, cidadeOrig, numchecCid) == -1){
			cout << "\nO Código Informado é inválido! Tente Novamente! \n";
			cin >> ca[i].codInst;
		}
		cout << "Informe o Máximo de Participantes da Turma: \n";
		cin >> ca[i].maxPartic;
		cout << "Informe o Total de Participantes da Turma: \n";
		cin >> ca[i].totPartic;
		while(ca[i].totPartic > ca[i].maxPartic){
			cout << "\nO Número total de Participantes não pode ser maior que o Máximo! \n";
			cin >> ca[i].totPartic;
		}
		cont++;
	}
}

void lerAddTur(
	turma ca[], 
	int &cont,
	turma turmOrig[],
	int numeroTurmCad,
	curso cursOrig[], 
	int numeroCursCad, 
	instrutor instOrig[], 
	int numeroInstCad,
	cidade cidadeOrig[],
	int numchecCid
){
	cont = 0;
	int numTur = 0;
	cout << "Cadastro de Turma:\n";
	cout << "Informe o número de Alunos que deseja Cadastrar:\n";
	cin >> numTur;
	for(int i = 0; i < numTur; i++){
		cout << "\nInforme o Código da Turma: \n";
		cin >> ca[i].codTur;
		while(checCodTur(turmOrig, numeroTurmCad, ca[i].codTur) == -1){
			cout << "\nO Código Informado é inválido! Tente Novamente! \n";
			cin >> ca[i].codTur;
		}
		cout << "Informe o Código do Curso a qual essa turma pertence: \n";
		cin >> ca[i].codCurs;
		while(checCodCurs(cursOrig, numeroCursCad, ca[i].codCurs) == -1){
			cout << "\nO Código Informado é inválido! Tente Novamente! \n";
			cin >> ca[i].codCurs;
		}
		cout << "Informe o Código do Instrutor: \n";
		cin >> ca[i].codInst;
		while(checInstValid(instOrig, numeroInstCad, ca[i].codInst, cidadeOrig, numchecCid) == -1){
			cout << "\nO Código Informado é inválido! Tente Novamente! \n";
			cin >> ca[i].codInst;
		}
		cout << "Informe o Máximo de Participantes da Turma: \n";
		cin >> ca[i].maxPartic;
		cout << "Informe o Total de Participantes da Turma: \n";
		cin >> ca[i].totPartic;
		while(ca[i].totPartic > ca[i].maxPartic){
			cout << "\nO total de Participantes não pode ser maior que o número Máximo! \n";
			cin >> ca[i].totPartic;
		}
		cont++;
	}
}

int checCodTur(turma ca[], int numchecTur, int novoCodTur){
	int inicio = 0;
	int fim = numchecTur - 1;
	int m = (inicio + fim) / 2;
	
	for (; fim >= inicio && novoCodTur != ca[m].codTur; m = (inicio + fim) / 2){
        if (novoCodTur > ca[m].codTur)
            inicio = m + 1;
        else
            fim = m - 1;
    }
    if (novoCodTur == ca[m].codTur){
    	cout << "\nTurma encontrada! Insira um novo código!";
        return -1;
    } else {
    	cout << "\nTurma não encontrada, código válido.";
    	return 1;
	}
}

void inclusaoTurma(turma original[], int contOri, turma novo[], int contN, turma addTur[], int &contAdd){
	int Ori = 0, Nov = 0, Add = 0;
    for (;Ori < contOri && Nov < contN; Add++){
        if (original[Ori].codTur < novo[Nov].codTur){
            addTur[Add].codTur = original[Ori].codTur;
            addTur[Add].codCurs = original[Ori].codCurs;
            addTur[Add].codInst = original[Ori].codInst;
            addTur[Add].maxPartic = original[Ori].maxPartic;
            addTur[Add].totPartic = original[Ori].totPartic;
            Ori++;
            }
        else {
            addTur[Add].codTur = novo[Nov].codTur;
            addTur[Add].codCurs = novo[Nov].codCurs;
            addTur[Add].codInst = novo[Nov].codInst;
            addTur[Add].maxPartic = novo[Nov].maxPartic;
            addTur[Add].totPartic = novo[Nov].totPartic;
            Nov++;
        }
    }
    while (Ori < contOri){
        addTur[Add].codTur = original[Ori].codTur;
        addTur[Add].codCurs = original[Ori].codCurs;
        addTur[Add].codInst = original[Ori].codInst;
        addTur[Add].maxPartic = original[Ori].maxPartic;
        addTur[Add].totPartic = original[Ori].totPartic;
        Ori++;
        Add++;
    }
    while (Nov < contN){
        addTur[Add].codTur = novo[Nov].codTur;
        addTur[Add].codCurs = novo[Nov].codCurs;
        addTur[Add].codInst = novo[Nov].codInst;
        addTur[Add].maxPartic = novo[Nov].maxPartic;
        addTur[Add].totPartic = novo[Nov].totPartic;
        Nov++;
        Add++;
    }
    contAdd = Add;
}

//Busca em Turma
int checTurValid(
	turma ca[], 
	int numChecTur,
	curso cb[],
	int numChecCur,
	instrutor cc[], 
	int numChecInst, 
	int checCodTur,
	int &i
){
	int inicio = 0;
	int fim = numChecTur - 1;
	int m = (inicio + fim) / 2;
	
	for (; fim >= inicio && checCodTur != ca[m].codTur; m = (inicio + fim) / 2){
        if (checCodTur > ca[m].codTur){
        	inicio = m + 1;
		}  
        else{
        	fim = m - 1;
		}   
    }
    if (checCodTur == ca[m].codTur){
    	//Busca para Curso
    	inicio = 0;
		fim = numChecCur - 1;
		i = (inicio + fim) / 2;
	
		for(; fim >= inicio && cb[i].codCurs != ca[m].codCurs; i = (inicio + fim) / 2){
        	if(cb[i].codCurs > ca[m].codCurs){
        		inicio = i + 1;
			} else {
				fim = i - 1;
			}	
    	}
    	
    	//Busca para Instrutor
    	int j;
    	inicio = 0;
		fim = numChecInst - 1;
		j = (inicio + fim) / 2;
	
		for(; fim >= inicio && cc[j].codInst != ca[m].codInst; j = (inicio + fim) / 2){
        	if(cc[j].codInst > ca[m].codInst){
        		inicio = j + 1;
			} else {
				fim = j - 1;
			}	
    	}
    	cout << "\nTurma encontrada!";
    	cout << "\nDescrição do Curso: " << cb[i].descCurs << ".";
        cout << "\nNome do Instrutor: " << cc[i].nomeInst << ".\n";
        cout << "\nValor por Aula: " << cb[i].valorAula << ".\n";
        return 1;
    } else {
    	cout << "\nTurma não encontrada, código inválido.";
    	return -1;
	}
}


// Funções Relacionadas a struct Matrícula ------------------------------------------------------------------

void lerMatri(
	matricula ca[], 
	int &cont,
	aluno aluOrig[],
	int numeroAluCad,
	cidade cidadeOrig[],
	int numchecCid,
	turma turmaOrig[], 
	int numeroTurCad,
	curso cursOrig[], 
	int numeroCursCad,
	instrutor instOrig[], 
	int numeroInstCad
){
	cont = 0;
	int numMat = 0;
	int numCur = 0;
	cout << "Cadastro de Matrícula:\n";
	cout << "Informe o número Matrículas:\n";
	cin >> numMat;
	for(int i = 0; i < numMat; i++){
		cout << "\nInforme o Código da Matrícula: \n";
		cin >> ca[i].codMatri;
		cout << "\nInforme o Código do Aluno: \n";
		cin >> ca[i].codAlu;
		while(checAluValid(aluOrig, numeroAluCad, ca[i].codAlu, cidadeOrig, numchecCid) == -1){
			cout << "\nO Código Informado é inválido! Tente Novamente! \n";
			cin >> ca[i].codAlu;
		}
		cout << "\nInforme o Código da Turma: \n";
		cin >> ca[i].codTur;
		while(
		checTurValid(
			turmaOrig, 
			numeroTurCad, 
			cursOrig, 
			numeroCursCad, 
			instOrig, 
			numeroInstCad, 
			ca[i].codTur, 
			numCur
		) == -1){
			cout << "\nO Código Informado é inválido! Tente Novamente! \n";
			cin >> ca[i].codTur;
		}
		cout << "\nInforme a Quantidade de Aulas: \n";
		cin >> ca[i].quantAulas;
		ca[i].valTot = float(cursOrig[numCur].valorAula * ca[i].quantAulas);
		cout << "\nValor total da Matrícula:" << ca[i].valTot << "\n";
	}
}

void lerAddMatri(
	matricula ca[], 
	int &cont,
	matricula matriOrig[],
	int numeroMatriCad,
	aluno aluOrig[],
	int numeroAluCad,
	cidade cidadeOrig[],
	int numchecCid,
	turma turmaOrig[], 
	int numeroTurCad,
	curso cursOrig[], 
	int numeroCursCad,
	instrutor instOrig[], 
	int numeroInstCad
){
	cont = 0;
	int numMat = 0;
	int numCur = 0;
	cout << "Cadastro de Matrícula:\n";
	cout << "Informe o número Matrículas:\n";
	cin >> numMat;
	for(int i = 0; i < numMat; i++){
		cout << "\nInforme o Código da Matrícula: \n";
		cin >> ca[i].codMatri;
		while(checCodMatri(matriOrig, numeroMatriCad, ca[i].codMatri) == -1){
			cout << "\nO Código Informado é inválido! Tente Novamente! \n";
			cin >> ca[i].codMatri;
		}
		cout << "\nInforme o Código do Aluno: \n";
		cin >> ca[i].codAlu;
		while(checAluValid(aluOrig, numeroAluCad, ca[i].codAlu, cidadeOrig, numchecCid) == -1){
			cout << "\nO Código Informado é inválido! Tente Novamente! \n";
			cin >> ca[i].codAlu;
		}
		cout << "\nInforme o Código da Turma: \n";
		cin >> ca[i].codTur;
		while(
		checTurValid(
			turmaOrig, 
			numeroTurCad, 
			cursOrig, 
			numeroCursCad, 
			instOrig, 
			numeroInstCad, 
			ca[i].codTur, 
			numCur
		) == -1){
			cout << "\nO Código Informado é inválido! Tente Novamente! \n";
			cin >> ca[i].codTur;
		}
		cout << "\nInforme a Quantidade de Aulas: \n";
		cin >> ca[i].quantAulas;
		ca[i].valTot = float(cursOrig[numCur].valorAula * ca[i].quantAulas);
		cout << "\nValor total da Matrícula:" << ca[i].valTot << "\n";
	}
}

//Checar código de Matrícula
int checCodMatri(matricula ca[], int numChecMatri, int novoCodMatri){
	int inicio = 0;
	int fim = numChecMatri - 1;
	int m = (inicio + fim) / 2;
	
	for (; fim >= inicio && novoCodMatri != ca[m].codMatri; m = (inicio + fim) / 2){
        if (novoCodMatri > ca[m].codMatri)
            inicio = m + 1;
        else
            fim = m - 1;
    }
    if (novoCodMatri == ca[m].codMatri){
    	cout << "\nMatrícula encontrada! Insira um novo código!";
        return -1;
    } else {
    	cout << "\nMatrícula não encontrada, código válido.";
    	return 1;
	}
}

void inclusaoMatri(
	matricula original[], 
	int contOri, 
	matricula novo[], 
	int contN, 
	matricula addMatri[], 
	int &contAdd
){
	int Ori = 0, Nov = 0, Add = 0;
    for (;Ori < contOri && Nov < contN; Add++){
        if (original[Ori].codMatri < novo[Nov].codMatri){
        	addMatri[Add].codMatri = original[Ori].codMatri;
            addMatri[Add].codAlu = original[Ori].codAlu;
            addMatri[Add].codTur = original[Ori].codTur;
            addMatri[Add].quantAulas = original[Ori].quantAulas;
            addMatri[Add].valTot = original[Ori].valTot;
            Ori++;
            }
        else {
            addMatri[Add].codMatri = novo[Nov].codMatri;
            addMatri[Add].codAlu = novo[Nov].codAlu;
            addMatri[Add].codTur = novo[Nov].codTur;
            addMatri[Add].quantAulas = novo[Nov].quantAulas;
            addMatri[Add].valTot = novo[Nov].valTot;
            Nov++;
        }
    }
    while (Ori < contOri){
        addMatri[Add].codMatri = original[Ori].codMatri;
        addMatri[Add].codAlu = original[Ori].codAlu;
        addMatri[Add].codTur = original[Ori].codTur;
        addMatri[Add].quantAulas = original[Ori].quantAulas;
        addMatri[Add].valTot = original[Ori].valTot;
        Ori++;
        Add++;
    }
    while (Nov < contN){
        addMatri[Add].codMatri = novo[Nov].codMatri;
        addMatri[Add].codAlu = novo[Nov].codAlu;
        addMatri[Add].codTur = novo[Nov].codTur;
        addMatri[Add].quantAulas = novo[Nov].quantAulas;
        addMatri[Add].valTot = novo[Nov].valTot;
        Nov++;
        Add++;
    }
    contAdd = Add;
}

