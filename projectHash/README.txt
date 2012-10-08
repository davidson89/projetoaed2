Procedimentos para compilação e execução:

Linux:
(1) Abra o terminal (ctrl + alt + T), navegue até o diretório onde encontram-se os códigos fontes (arquivos .cpp e .h) e makefile, digite make para compilar o programa e criar o arquivo executavel.

(2) Após ter executado o comando make em seu terminal, será criado um arquivo executavel com nome ep1.

(3) Para executar o programa digite ./ep1 <nomeDoArquivoComAsPalavras>. Este é o parâmetro de inicialização que carregará a tabela Hash com as palavras do arquivo words.txt, por exemplo.

Exemplo de execução: ./ep1 words.txt


Windows:
(1) Abra o prompt de comando, navegue até os diretórios onde encontram-se os códigos fontes (arquivos .cpp e .h), e digite g++ -o ep1.exe main.cpp HashTable.cpp Les.cpp. (Obs: É necessário possuir o compilador MinGW instalado).

(2) Após ter executado o comando acima no seu prompt, será criado um arquivo executavel com o nome ep1.exe.

(3) Para executar o programa digite ep1.exe <nomeDoArquivoComAsPalavras>. Este é o parâmetro de inicialização que carregará a tabela Hash com as palavras do arquivo words.txt, por exemplo.

Exemplo de execução: ep1.exe words.txt
