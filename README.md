# Trabalho-Prático

Pontifícia Universidade Católica de Minas Gerais

Instituto de Ciências Exatas e Informática

Curso de Engenharia de Software

Disciplinas: Algoritmos e Estruturas de Dados I  / Fundamentos de Engenharia de Software

Professores: Carlos Ribas e Laerte                Entrega: 15/12/2024                 Valor: 10 pontos

# Integrantes:

- [Wesley Domingos](https://github.com/WesleySDz)  
- [Nicolas Kiffer](https://github.com/nicolasksoares)  
- [Luiz Moreira](https://github.com/LuizFMoreira)  
- [Matheus Malta](https://github.com/MatheusSMalta)  


# Objetivo:

O objetivo é realizar um sistema de gerenciamento para a Voo Seguro, que subtitua os métodos manuais antigos. Para isso propomos um software feito na linguagem C que irá auxiliar-los por meio da automatização do controle de dados. A solução incluirá uma interface intuitiva, projetada para facilitar o uso com uma gama de comandos e funções para isso.

# Backlog to produto:
#Sprint 1: Na primeira imagem, mostramos o quadro Kanban após a primeira sprint. Primeiro, entendemos os requisitos do trabalho e realizamos a divisão das tarefas que cada membro irá realizar, os níveis de dificuldade, o tempo estimado, o tamanho de cada tarefa e os seus níveis de prioridade. Por fim, mostramos os progressos que cada tarefa irá fazer ao decorrer das sprints.
![Sprint 1](img/Backlog-do-produto.png)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#Sprint 2: Na segunda imagem, mostramos o quadro Kanban após a segunda sprint. Começamos os primeiros passos para desenvolver o código, iniciando com as funcionalidades de cadastrar passageiro, realizar reserva, cadastrar assento e, por último, o programa de fidelidade(Cada função com seu devido nivel de dificuldade e prioridade).
![Sprint 2](img/Backlog-do-produto2.png)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#Sprint 3: Entendemos os problemas
![Sprint 3](img/Backlog-do-produto3.png)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#Sprint 4: Entendemos os problemas
![Sprint 4](img/Backlog-do-produto4.png)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#Sprint 5: Entendemos os problemas
![Sprint 5](img/Backlog-do-produto5.png)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#Sprint 6: Na quinta imagem, mostramos o quadro Kanban após a quinta sprint. Realizamos os testes utilizando a biblioteca unit nas funções que foram realizadas na ultima sprint(4), os testes foram nas funções de cadastrar voo, cadastrar tripulação, pesquisa e dar baixa em reservas, e também é perceptivel o andamento das nossas tarefas ao decorrer das sprints. 
![Sprint 6](img/Backlog-do-produto6.png)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#Sprint 7: Entendemos os problemas
![Sprint 7](img/Backlog-do-produto7.png)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#Sprint 8: Entendemos os problemas
![Sprint 8](img/Backlog-do-produto8.png)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#Sprint 9: Entendemos os problemas
![Sprint 9](img/Backlog-do-produto9.png)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#Sprint 10: Entendemos os problemas.
![Sprint 10](img/Backlog-do-produto10.png)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Lista de assinaturas das funções e parâmetros
Explicação da estrutura de dados principal do programa.

As funções e parâmetros utilizados no programa foram:

## *1.* int main () - Menu de opções

Função para efetuar qual funcionalidade o usuario irá requerir, basicamente ira gerar um menu de opções e irá solivcitar ao usuario inserir uma opção válida.

## *2.* int verificarEspacosBrancos(const char *str)

Função que recebe um string para verificar se o usuario digitou apenas espaços em brancos em determinadas partes do programa, resolicitando a sua digitação.

## 3. void buscarPassageiro() 

Função que busca o passageiro pelos dados. Aparecerá uma aba perguntando se você deseja pesquisar pelo nome ou pelo código do passageiro. Digite 1 para nome e 2 para o código. Se os dados estiverem errados ou inexistentes, aparecerá a mensagem: "Nenhum passageiro encontrado com o nome informado." Caso o passageiro seja encontrado, serão exibidos o nome, endereço e o status de fidelidade do respectivo passageiro.

## 4. void buscarTripulante()

Função que busca o tripulante pelo nome.Aparecerá uma aba perguntando se você deseja pesquisar pelo nome ou pelo código do tripulante. Digite 1 para nome e 2 para o código.Se os dados estiverem errados ou inexistentes, aparecerá a mensagem: "Nenhum tripulante encontrado com o nome informado." Caso o tripulante seja encontrado, serão exibidos nome, cargo e o telefone do respectivo tripulante.

## 5. void listarVoosPassageiro()

Função que lista todos os voos de um passageiro: A função solicitará que você digite o código do passageiro. Caso o código esteja incorreto ou não exista, será exibida a mensagem: "Passageiro não encontrado." Se o código for válido, serão exibidos todos os voos associados a esse passageiro.

## 6. void pesquisa()

Função de menu de pesquisa. Esta função permite escolher entre buscar passageiros, buscar tripulantes, listar os voos de um passageiro ou sair da aba de pesquisa. A primeira opção direciona para a pesquisa de passageiros, a segunda para a pesquisa de tripulantes, a terceira para a pesquisa de voos do respectivo passageiro, e a quarta encerra a sessão de pesquisa.

## 7. int verificarAssento(int numeroAssento, int codV) 

Função para verificar se o assento escolhido, existe no voo escolhido.  

## 8.  void cadastrarAssento() 

Função para cadastro de assentos. O administrador digita a quantidade máxima de assentos. Se o assento já estiver cadastrado, aparecerá 'assento já cadastrado'. Se os dados do voo estiverem incorretos, aparecerá 'código de voo inválido'. 

## 9.  void listarAssento() 
 
Função para listar a quantidade de assentos no respectivo voo, aparecera a mensagem “Nenhum assento cadastrado” se nenhum assento estiver cadastrado, nesta função você cadastrara o número de assento, o código do respectivo voo, os status do assento, se ele está livre aparecera “livre” e se estiver ocupado aparecera “ocupado”. 

## 10.  void darBaixa() 

Esta função realiza a baixa na reserva de assento do respectivo voo. Nela, você digita o número do assento e o código do voo. Se os dados estiverem corretos, o assento será reservado para o passageiro. Caso algum dos dados esteja errado, aparecerá a mensagem 'assento ou voo não encontrado'. 

## 11. int verificarAssento(int numeroAssento, int codV) 

Função com passagem de parâmetro e com retorno, recebe dois inteiros, os números de assento e o código do voo. É utilizada para verificar se o assento está ocupado ou não.

## 12. int verificarPassageiro(int id) 

Função com passagem de parâmetro e com retorno, recebe o inteiro ID, cuja finalidade é verificar se o passageiro existe.

## 13. void reserva() 

Função que não recebe parâmetros e não retorna nada, garantindo que o passageiro tenha um assento. Ela verifica se o passageiro e o assento estão cadastrados, confirma a disponibilidade e, se todos os dados estiverem corretos, realiza a associação entre o passageiro e o voo.

## 14. int verificarEspacosBrancos(const char *str) 

Função que recebe um string para verificar se o usuario digitou apenas espaços em brancos em determinadas partes do programa, resolicitando a sua digitação. 


## 15. void addPassageiro() 

Função sem passagem de parâmetro e sem retorno, com a finalidade de adicionar os dados dos passageiros (ID, nome, endereço, fidelidade). Ao atingir 99 passageiros, a função exibe a mensagem 'limite de passageiros'. 

## 16. int continua() 

função que não recebe parâmetros e retorna um valor. Essa função tem como objetivo perguntar ao passageiro se ele deseja continuar cadastrando ou encerrar para exibir os cadastros realizados. O retorno será 1 caso o passageiro escolha continuar, e 2 caso opte por parar e visualizar os cadastros. 

## 17. void lerPassageiros() 

Função sem passagem de parametro e sem retorno, que tem como funcionalidade mostra os dados (ID, nome, endereço, telefone, fidelidade) dos passageiros cadastrados. 

## 18. int verificarAssento(int numeroAssento, int codV) 

Função com passagem de parâmetro e com retorno, recebe dois inteiros, os números de assento e o código do voo. É utilizada para verificar se o assento está ocupado ou não.

## 19. int verificarPassageiro(int id) 

Função com passagem de parâmetro e com retorno, recebe o inteiro ID, cuja finalidade é verificar se o passageiro existe.

## 20. void reserva() 

Função que não recebe parâmetros e não retorna nada, garantindo que o passageiro tenha um assento. Ela verifica se o passageiro e o assento estão cadastrados, confirma a disponibilidade e, se todos os dados estiverem corretos, realiza a associação entre o passageiro e o voo.

## 21. void acumularPontos(int idPassageiro)

Função para acumular os pontos obtidos pelo passageiro: Após reservar um assento no voo, o passageiro recebe 10 pontos. Esta função é responsável por acumular os pontos obtidos por cada passageiro.

## 22. void consultarPontos(int idPassageiro)

Função para consultar pontos de fidelidade pelo ID. Esta função mostra o respectivo passageiro e quantos pontos ele tem.

## 23. void fidelidade()

Esta função mostra 3 opções, a primeira é para consultar os pontos de fidelidade, a segunda é para acumular os pontos, e a terceira é para sair da aba de fidelidade. A primeira e segunda você digita o ID do passageiro para consultar os pontos do mesmo.

## 24. void obterString(char mensagem[], char destino []) 

Essa função é responsável por obter uma string válida do usuário. Ela exibe uma mensagem para o usuário e continua solicitando a entrada até que o valor fornecido não seja vazio. 

## 25. Int obterInteiro(char mensagem[]) 

Essa função solicita ao usuário um número inteiro positivo. Ela valida a entrada, garantindo que seja um valor maior que zero. Em caso de erro, informa ao usuário e pede a entrada novamente. 


## 26. Int obterFloat(char mensagem[]) 

Semelhante à função anterior, mas usada para obter um número decimal positivo (valor do tipo float). Também valida a entrada e solicita novamente em caso de erro. 

 
## 27. Int validarData(char Data[]) 

Função com passagem de parâmetro e retorno, que recebe a variável Data e tem como objetivo validar as datas do voo.

## 28. Int validarHora(char hora[]) 

Função com passagem de parâmetro e retorno, que recebe a variável hora e tem como objetivo validar os horários do voo. 

## 29. Int verificarDuplicidade(Voo voos[], int total, Voo novoVoo) 

Função com passagem de parâmetros e retorno, que recebe as variáveis e o struct (Voo voos[], int total, Voo novoVoo) com o objetivo de verificar se há duplicidade de informações entre o novo voo e a lista de voos já cadastrados. 

## 30. Void registrarVoo(Voo *voo, Voo voos[], int totalVoos) 

Função que recebe como parâmetros as variáveis e o struct (Voo *voo, Voo voos[], int totalVoos), cuja finalidade é registrar novos voos, validar os dados do voo, e ver se há duplicidade em voos já cadastrados  

## 31. Void exibierVoo(Voo *voo) 

Função para exibir todos os dados do voo. Mostra os dados como (ID, data, hora, origem, destino, IDS de tripulante, status (ativo ou inativo) e tarifa. 





# TESTES:

## Menu:
|ENTRADAS | CLASSES VÁLIDAS | RESULTADO ESPERADO | CLASSES INVÁLIDAS | RESULTADO ESPERADO|
|--------|-----------------|-------------------|--------------------|-------------------|
|Numeros inteiros | Opção existente | Acessar funcionalidade | Numeros negativos, acima de 8 e nulos | Opção inválida|

## Espaços em brancos
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Texto    |   Texto     | Cadastrar informação     | Espaços brancos, tabulação e nova linha | É solicitadoa ao usuario escrever| novamente o texto|

## Adicionar passageiros
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Informação validas    |   Texto alfabético ou numérico     | Passageiro cadastrado     | Fidelidade com qualquer valor diferente de "Sim" ou "Não". Nome vazio ou caracteres invalidos | É solicitado ao usuario escrever novamente|

## Adicionar tripulação
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Nome, cargo, telefone | Nome com apenas letras e espaços. Codigo numerico representando o cargo. Int com comprimento válido | Tripulante salvo | Nome em branco. Crago com letras, caracteres especiais ou vazios. Telefone com letras, negativos ou vazios | Informar ao usuario erro que não foi possível cadastrar o tripulante |

## Adicionar assentos
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Id do assento, codigo do voo | Id dentro do limite e existente, codigo do voo dentro do limite e existente e assento previamente não cadastrado | Cadastrar assento para denterminado voo | Id e codigo de voo negativo, nulo, além do limite e duplicado| Informar ao usuario que os dados não podem ser cadastrados |

## Realizar reservas
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Id do assento, codigo do voo, codigo do pasasgeiro | Ids dentro do limite e existente, codigo do voo dentro do limite e existente, assento não ocupado | Realizar reserva para o codigo do passageiro descrito | Ids negativos e codigo do voo negativo, nulo, além do limite e duplicado | Mostrar que não foi possível realizar a reserva de acordo com a quebra feita |

## Dar baixa em assento
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Numero e codigo do voo| Assento previamente reservado e existente | Altere o status para livre e remova o ID do passageiro |  Assento inexistente ou livre | Informar que o assento não está reservado ou inexistente|

## Fidelidade
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Codigo de pasasgeiro | Passageiro previamente cadastrado e com fidelidade | Acumular 10 pontos ao passageiro. Mostrar a quantidade de pontos do passageiro | Passageiro não cadastrado previamente ou passageiro sem fidelidade |Ilustrar ao ussuario que não foi possivel realizar a operação |

# RELATORIO DE EXECUÇÃO DE TESTES:
## Menu: 
Teste 1: Menu de opções

| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Número inteiro    | Números de 1 a 8        | Acessar funcionalidade     | Números negativos, acima de 8 e nulos | Opção inválida |      

 Relatório de execução de testes

| ENTRADAS   | RESULTADO                | APROVADOS |
|------------|--------------------------|-----------|
| Valor: -5  | Opção inválida           | Sim       |
| Valor: 0   | Opção inválida           | Sim       |
| Valor: 1   | Cadastrar Passageiro     | Sim       |
| Valor: 2   | Cadastrar Tripulação     | Sim       |
| Valor: 3   | Cadastrar Voo            | Sim       |
| Valor: 4   | Cadastrar Assento        | Sim       |
| Valor: 5   | Reserva                  | Sim       |
| Valor: 6   | Baixa em reserva         | Sim       |
| Valor: 7   | Pesquisa                 | Sim       |
| Valor: 8   | Programa de fidelidade   | Sim       |
| Valor: 20  | Opção inválida           | Sim       |
## Espaço em branco
Teste 1: Verificar espaços brancos
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| String    |   String     | Cadastrar informação     | Espaços brancos, tabulação e nova linha | É solicitadoa ao usuario escrevre |novamente o texto|

Relatório de execução de testes:


| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| Valor: " "   | Texto invalido           | Sim       |
| Valor: "Bom" | Texto válido             | Sim       |
| Valor: ""    | Texto invalido           | Sim       |
| Valor: \t\n  | Texto invalido           | Sim       |
| Valor: " Opa"| Texto Válido         | Sim       |

## Adicionar passageiros
Teste 1: Verificar adicionamento de passageiros
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
|  Strings e inteiros   |   Texto valido, pontos não negativos e fidelidade como 1 ou 2     | Informar ao usuario os dados cadastrados     | Strings vazias, numeros negativos e opçoes além do escopo de opção | É solicitado ao usuario escrever novamente| 

Relatorio de execução de testes:
| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| Nome: "Wesley"   | Texto válido           | Sim       |
| Endereço: "Rua" | Texto válido             | Sim       |
| Numero: "40028922"    | Texto válido           | Sim       |
| Fidelidade: "1"  | Opção válida          | Sim       |
| Pontos: "1500"| Quantidade válida         | Sim       |

## Adicionar tripulação
Teste 1: Adicionar tripulação
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Strings e inteiros | Numeros não negativos e não nulos, telefone com no minimo 8 caracteres. Nome sem ser espaços em brancos. Cargo dentro do limite | Cadastro realizado | Numeros negativos e nulos, telefone com menos de 8 caracteres. Nome em branco | Registro não realizado |

Relatorio de execução de testes:
| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| Id: "1"      | Id salvo                 | Sim       |
| Nome: "João" | Nome salvo               | Sim       |
| Cargo: "1"   | Cargo salvo              | Sim       |
| Telefone: "40028922" | Telefone salvo   | Sim       |

Teste 2: Verificar cargos
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Inteiros | Piloto : 1, Copiloto: 2, Comissário: 3 | Registrar o cargo | Negativo, nulo, maior que 3 | Peder novamente a inserção |

Relatorio de execução de testes:
| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| Cargo: "1"   |  Piloto                  | Sim       |
| Cargo: "2"   |  Copiloto                | Sim       |
| Cargo: "3"   |  Comissário              | Sim       |
| Cargo: "0"   |  Inexistente             | Sim       |
| Cargo: "-5"  |  Inexistente             | Sim       |
| Cargo: "17"  |  Inexistente             | Sim       |

Teste 3: Verificar telefone
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Inteiros   |   Telefones com mais de 8 digitos e não negativos | Telefone cadastrado | Telefone com menos de 8 digitos e negativos | Telefone não cadastrado |

Relatorio de execução de testes:
| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| Telefone: "-12345678" |  Telefone não válido  | Sim       |
| Telefone: "12345" |  Telefone não válido  | Sim       |
| Telefone: "40028922" |  Telefone válido  | Sim       |

## Adicionar assentos

Teste 1:  Limite de assentos cadastrados atingido
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Inteiros         | Valores maiores que o limite| Erro ao cadastrar       | Numeros dentro do limite      | Executar a função de cadastrar     |

Relatorio de execução de teste
| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| Valor: "10000"   | Impossivel cadastrar           | Sim       |

Teste 2: Cadastrar assento
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Inteiros         | Numeros inteiros positivos e não nulos que não extrapolam o limite| Cadastrar o assento | Numeros negativos, nulo e que extrapolam o limite| Informar ao usuario uma nova solicitação|

Relatorio de execução de teste
| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| Assento: -1 Voo: -5 |   Cadastro inválido         | Sim       |
| Assento: -1 Voo: 0 |   Cadastro inválido         | Sim       |
| Assento: -1 Voo: 5 |   Cadastro inválido         | Sim       |
| Assento: 0 Voo: -5 |   Cadastro inválido         | Sim       |
| Assento: 0 Voo: 0 |   Cadastro inválido         | Sim       |
| Assento: 0 Voo: 5 |   Cadastro inválido         | Sim       |
| Assento: 17 Voo: -5 |   Cadastro inválido         | Sim       |
| Assento: 17 Voo: 0 |   Cadastro inválido         | Sim       |
| Assento: 17 Voo: 5 |   Cadastro válido         | Sim       |

Teste 3: Verificar assento vazios
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Inteiros         | Listar assentos sem antes cadastrar | Informar que não existe | Listar assentos já pre-cadastrados | Mostrar o sassentos cadastrados|

Relatorio de execução de teste
| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| Total de assentos: 0 |   Busca inválida         | Sim       |

Teste 4: Assento duplicado
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Inteiros         | Repeti o mesmo numero de assento e voo | Informar que o assento já existe | Informar outro assento | Realizar o cadastro|

Relatorio de execução de teste
Cadastramos o assento 17 05 e verificamos se ele já é existente
| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| Assento: 17 Voo: 5 |   Voo duplicado         | Sim       |

## Realizar reserva
Teste 1: Assento livre
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Inteiros   | Assento pre-cadastrado, livre, passageiro cadastrado | Reserva feita com sucesso | Assento inexistente, ocupado, passageiro não encontrado | Reserva não concluída |

Relatorio de execução de teste
| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| Assento: 17  Voo: 5 Passageiro: 1 | Assento   reservado |  Sim    |

Teste 2: Assento ocupado
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Inteiros   | Assento com status ocupado | Não foi possivel cadastrar | Assento com status livre | Reserva feita |

Relatorio de execução de teste
| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| Assento: 17  Voo: 5 Passageiro: 1 | Assento ocupado |  Sim    |

Teste 3: Assento não encontrado
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Inteiros | Assento não cadastrado previamente | Não foi possivel realizar a reserva | Assento previamente cadastrado | Reserva feita |

Definimos um unico assento 17, 05

Relatorio de execução de teste
| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| Assento: 18 Voo: 5  | Assento não encontrado |  Sim    |
| Assento: -5 Voo: 0  | Assento não encontrado |  Sim    |
| Assento: 5 Voo: 0  | Assento não encontrado |  Sim    |

Teste 4: Passageiro não encontrado
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Inteiros | Passageiro cadastrado  | Assento reservado com sucesso | Id do passageiro não cadastrado | Erro ao fazer reserva |

Definimos um unico passageiro com id=1

Relatorio de execução de teste
| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| Assento: 17 Voo: 5 Passageiro: -1 | Passageiro não encontrado |  Sim    |

## Dar baixa em assento

Teste 1: Tentar da baixa em assento ocupado, não existente ou livre
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Inteiros         | Assentos existentes      | Informar ao usuario que o assento foi desocupado e transforma o seu status em livre e desvincular o passageiro vinculado | Assento inexistente ou não ocupado | Infprmar ao usuario que o assento digitado não existe ou está livre |

Colocamos tres acertos e tentamos da baixa em cada um.

Definimos o primeiro teste com um assento ocupado e existente codigo 17, voo 5, ocupado.

Definimos o segundo teste com um assento livre e existente codigo 22, voo 5, livre.

Definimos o terciro teste com um assento inexiste. O original é 27, 5.

Relatorio de execução de teste
| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| id="17" voo="5"    | Baixa com sucesso  | Sim       |
| id="22" voo="5"    | Assento não está ocupado | Sim |
| id="29" voo="15"   | Assento não existe | Sim       |

## Fidelidade

Teste 1: Menu de opções
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Inteiros | Numeros entre 1 a 3 | Acessar funcionalidade | Informar ao usuario a quantidade de pontos do usuario, ou acumular pontos ao usuario | Numeros negativos, nulos ou acima de 3 | Solicitar novamente a inserção da opção |

Relatorio de execução de teste

| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| Valor: "-1"  | Opção inexistente        | Sim       |
| Valor: "0"   | Opção inexistente        | Sim       |
| Valor: "1"   | Consultar pontos         | Sim       |
| Valor: "2"   | Acumular pontos          | Sim       |
| Valor: "3"   | Sair do menu             | Sim       |
| Valor: "17"  | Opção inexistente        | Sim       |

Teste 2: Consultar pontos
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Inteiros | Codigo de passageiro existente e que possui fidelidade| Mostrar a quantidade de pontos que possui | Codigo inexistente, negativo ou nulo | Informar que não foi encontrado o passageiro|

Relatorio de execução de teste

| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| Id: "1"      | Passageiro encontrado    | Sim       |
| Id: "0"      | Passageiro não encontrado | Sim      |
| Id: "-1"     | Passageiro encontrado    | Sim       |

Teste 3: Acumular pontos
| ENTRADAS         | CLASSES VÁLIDAS          | RESULTADO ESPERADO         | CLASSES INVÁLIDAS             | RESULTADO ESPERADO    |
|-------------------|--------------------------|----------------------------|-------------------------------|-----------------------|
| Inteiros | Código de passageiro existente e que possui fidelidade | Adicionar 10 pontos de fidelidade ao usuario | Código inexistente, negativo, não, nulo ou que não tem fidelidade | Informar que não foi possivel acumular pontos |

Relatorio de execução de teste

| ENTRADAS     | RESULTADO                | APROVADOS |
|--------------|--------------------------|-----------|
| Id: "1"      | Mais 10 pontos acumulado   | Sim       |
| Id: "0"      | Não foi possivel encontrar | Sim      |
| Id: "-1"     | Não foi possível encontrar    | Sim       |

O trabalho poderá ser feito em grupos de até 4 alunos,
Cópias de trabalho receberão nota ZERO.
O programa deve ser desenvolvido na linguagem de programação C e deverá ser entregue pelo Canvas até as 23:59 horas do dia 15/12/2024.
O grupo deve preparar uma apresentação gravada com a participação de todos os seus componentes. Essa apresentação também deverá ser entregue no Canvas em todas as disciplinas participantes do trabalho interdisciplinar.
Deverá ser entregue o projeto completo do programa, a documentação, os arquivos contendo os testes realizados e a apresentação gravada em todas as disciplinas participantes do trabalho interdisciplinar.
Em caso de dúvidas, entre em contato com seu professor.
Companhia Aérea Voo Seguro

A Voo Seguro é uma companhia aérea que visa garantir a satisfação de seus passageiros e promover sua fidelização. Ela opera em vários aeroportos pelo Brasil e conta com uma equipe de tripulação composta por pilotos, copilotos e comissários. Atualmente, o controle de voos, reservas e tripulação é realizado em planilhas e cadernos, o que tem gerado diversos problemas, como reservas duplicadas e falta de controle sobre a disponibilidade de voos e assentos.

 Para resolver esses problemas, a Voo Seguro contratou uma equipe de desenvolvedores de software (vocês) para desenvolver um sistema de gerenciamento de voos.

 

O Sistema

Deseja-se cadastrar passageiros, tripulação e voos da companhia aérea.

As informações a serem cadastradas são:

PASSAGEIRO: código, nome, endereço, telefone, fidelidade (sim/não), pontos fidelidade.
TRIPULAÇÃO: código, nome, telefone, cargo (piloto, copiloto, comissário).
VOO: código do voo, data, hora, origem, destino, código do avião, código do piloto, código do copiloto, código do comissário, status (ativo/inativo), tarifa.
ASSENTO: número do assento, código do voo, status (ocupado/livre).
RESERVA: código do voo, número do assento, código do passageiro.
 

Considere as seguintes restrições: ** Não se esqueça de sempre validar essas restrições

Para cadastrar uma reserva, é necessário que o passageiro e o voo estejam previamente cadastrados.

Reservas podem ser feitas apenas para voos com status ativo e com assentos disponíveis.

A tripulação de cada voo deve conter ao menos um piloto e um copiloto para que o voo seja considerado ativo.

Cada assento deve ser ocupado por apenas um passageiro em um determinado voo, e um voo não deve ter o mesmo assento reservado para mais de um passageiro.

Funcionalidades a Implementar:

Cadastro de Passageiro:
- Deve garantir que não haja dois passageiros com o mesmo código.

- Opcionalmente, pode-se gerar o código automaticamente.

Cadastro de Tripulação:
- Cada membro da tripulação deve ter um cargo específico.

- Deve garantir que não haja dois membros da tripulação com o mesmo código.

- Opcionalmente, pode-se gerar o código automaticamente.

Cadastro de Voo:
- Deve ser possível cadastrar informações sobre data, hora, origem, destino, tarifa, tripulação e o avião.

- Deve verificar a presença de ao menos um piloto e um copiloto para que o voo seja marcado como ativo.

Cadastro de Assento:
- Deve ser possível cadastrar os assentos de cada voo.

Reserva:
- Deve garantir que o assento esteja disponível antes de reservar.

- Reservas duplicadas para o mesmo assento no mesmo voo devem ser evitadas.

Baixa em Reserva:
- Deve liberar o assento e atualizar o status para livre.

- Calcular o valor total a ser pago, se necessário, de acordo com a tarifa do voo.

Pesquisa:
- Deve ser possível buscar passageiros e membros da tripulação pelo nome ou código.

- Deve ser possível listar todos os voos de um determinado passageiro.

Programa de Fidelidade:
- Cada voo concede 10 pontos de fidelidade ao passageiro.

- Um passageiro pode acumular pontos ao longo de múltiplos voos.

 

Para implementar este programa pode ser necessário criar mais funções do que as que estão descritas.

Finalmente, implemente uma função main() que teste o sistema acima.

A função main() deve exibir um menu na tela com as opções de cadastrar passageiro, tripulação, voo, assento, reserva, baixa em reservas, pesquisa e consulta ao programa de fidelidade.

Esse menu deve ficar em loop até o usuário selecionar a opção SAIR.

Metodologia

Este é um trabalho interdisciplinar em que você deve planejar, analisar, projetar, implementar e testar uma solução de software para o problema apresentado utilizando o Scrum para gerenciar seu progresso.

Inicialmente organize o backlog do produto com as funções básicas do sistema. Cada um dos módulos (procedimentos ou funções) será de responsabilidade de um membro do grupo e será desenvolvido em sprints de 3 a 4 dias.

Seguem algumas sugestões de atividades a serem realizadas nas sprints:

Definir a assinatura dos módulos (procedimentos e funções) e documentar seus parâmetros. Reflita sobre os parâmetros de entrada e saída do módulo e comunique aos seus colegas de projeto.
Documentar o módulo (procedimento ou função) indicando seu propósito, parâmetros de entrada e saída. O nome do módulo deve ser escolhido sob o ponto de vista de quem o usa ou de quem vai chamar o módulo e deve refletir o que ele faz.
Implementar o caso de sucesso do módulo (procedimento ou função).
Selecionar casos de teste para verificar o funcionamento de cada módulo. Um caso de teste deve conter os valores de entrada para o módulo e a saída esperada.
Executar os casos de teste planejados para o módulo.
Criar um relatório de execução de testes que contenha os casos de teste, a saída retornada durante sua execução e uma indicação se o módulo passou ou não no teste. Isso é feito comparando-se a saída esperada, documentada no caso de teste, com a saída retornada durante a execução do módulo (esperado x real).
Implementar os casos especiais, exceções que possam existir no módulo (procedimento ou função). Em seguida, executar os casos de teste anteriores para garantir que as mudanças não quebraram o código anterior que já funcionava. Pense também em novos casos de teste necessários para a nova versão do módulo (procedimento ou função).
O que Deve ser Entregue

A evolução do backlog do produto a cada sprint. Indique quais tarefas encontravam-se inicialmente no backlog do produto, e em qual sprint cada tarefa foi alocada, juntamente com seu responsável.
A documentação das funcionalidades do software.
O planejamento dos casos de teste (entradas, procedimento de teste e saídas esperadas) e o relatório de execução dos testes.
O código em C, dos módulos (funções e procedimentos) e do programa principal, juntamente com o projeto completo do software.
Arquivos contendo dados já incluídos para teste das funcionalidades.
Apresentação gravada em vídeo (pitch) mostrando todas as funcionalidades do sistema.
