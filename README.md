## Example of artificial neural network. Multi-Layer Perceptron network created with FANN.

mlp1: Classification problem
mlp2: Function approximation problem


Detailed description: (Only portuguese, sorry :/)



### Introdução

Para implementar uma aplicação com RNA alguns cuidados devem ser tomados. De acordo com o portal do software Qnet (QNET) \cite{QNET}, primeiramente o modelo da rede é formulado. Depois, estipulam-se quais seriam as entradas e saídas para se ter uma idéia do que se quer prever ou determinar pela rede. Finalmente, que fatores influenciam as saídas, ou seja, que dados a rede usa para prever a resposta. É usual começar com poucos números de entradas, adicionando e reformulando a rede pouco a pouco.

Abaixo são mostradas as partes que compõem o desenvolvimento de uma RNA:

\textbf{Classe de treinamento:} utilizada para o treinamento da rede. São as entradas de dados que irão  "moldar" a rede, criar um modelo, um padrão para reconhecer futuramente novas entradas. As novas serão comparadas com a rede treinada e assim produzirão uma resposta comparativa à entrada em questão;
\textbf{Classe de teste:} outra população de entradas semelhantes irá ser inserida na rede para averiguar o resultado final. O resultado final da rede depende do deferimento das condições mínimas delimitadas pelo problema que podem ser aceitas. Ambos conjuntos de dados foram obtidos no repositório UCI \cite{UCI};
\textbf{Processamento dos dados:} agora os dados de entrada precisam ser tratados para que a rede absorva as informações necessárias e descarte as desnecessárias. Logo após, determina-se o tipo de formatação de cada entrada. Algumas perguntas são importantes para determinar o modelo como: As entradas são independentes? Existirá uma hierarquia de valores ou cada entrada vai gerar um estímulo binário?


Em seguida, vem a criação e a forma de representar a rede. Segundo \cite{RIBEIRO99}, três passos são determinados:
\begin{itemize}
\item Selecionar a função de ativação de cada camada. Nesse projeto a função utilizada foi \textit{Sigmoid} para a maioria dos problemas;
\item Determinar topologia da rede utilizada, avaliando número de camadas e a quantidade de neurônios de cada uma dessas. É interessante começar com camadas simples para se ter uma validação mais rápida.
\item Finalmente os algoritmos de treinamento. Nesse caso o \textit{Backpropagation};
\end{itemize}

Posteriormente, a rede é treinada. Nessa etapa, é que acontece o ajuste de pesos entre as camadas, sendo que valores iniciais bem escolhidos determinam menor tempo de treinamento. Outro fator importante é o tempo de treinamento, cada instante de finalização tem que ser bem avaliado, evitando \textit{over-training} (especialização demasiada). Quando a rede apresentar uma taxa de erro e generalização aceitável, ela estará bem treinada.

Finalmente, a rede é testada. A classe de teste coletada no início do projeto da rede agora vai determinar o desempenho e considerações finais. Todas as variáveis em questão são reavaliadas como, por exemplo, desempenho geral da rede, pesos, saídas satisfatórias, entre outras.

Nessa seção veremos duas aplicações distintas para redes neurais artificiais.

#### MLP

Para implementar as redes MLP a biblioteca FANN \cite{fann} foi utilizada.  Essa é uma bilbioteca \textit{opensource} para o desenvolvimento de redes neurais que implementa redes multi-camadas em C, com suporte para redes total ou parcialmente ligadas. Ela possui implementação multi-plataformas e suporta tanto operações com ponto fixo quanto flutuante.

#### Classificação (mlp1)
Para o problema de classificação foi utilizada uma rede com 4 entradas, 2 saídas e 1 camada interna com 15 neurônios. A condição de parada foi para um erro quadrático médio menor que 0.003.  Essa rede é construída pelo programa "mlp1.c" e salva no arquivo "mlp1.net".

Os dados utilizados foram retirados do repositório UCI \cite{UCI} e divididos em duas partes: treinamento ("entrada.data") e validação ("run.data"). Os dados são do conjunto identificado como "IRIS". O conjunto informa 4 medidas (em centímetros) de um grupo de plantas e as classifica em três tipos: Iris Setosa, Iris Versicolour e Iris Virginica. Essas saídas foram codificadas respectivamente para \{1,-1,-1\}, \{-1,1,-1\}, \{-1,-1,1\} e a resposta de maior valor foi interpretada a classe esperada. Essa base é comumente utilizada em trabalhos sobre RNA e possui 130 entradas.


#### Aproximação de Funções mlp2

Para o problema de aproximação de funções foi utilizada uma rede com 1 entradas, 1 saída e 1 camada interna com 15 neurônios. A condição de parada foi para um erro quadrático médio menor que 0.0003.  Essa rede é construída pelo programa "mlp2.c" e salva no arquivo "mlp2.net".

Os dados utilizados foram criados pelo programa "geradorFuncao.cpp", que gera aproximadamente 400 valores randômicos da função seno, e divididos em duas partes com aproximadamente 200 entradas: treinamento ("entrada.data") e validação ("run.data"). Foi necessário normalizar a entrada dos dados, e garantir que tanto os dados do treinamento quanto da validação cobrissem todo o intervalo da função.
