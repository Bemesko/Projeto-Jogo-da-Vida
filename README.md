# SUPER JOGO DA VIDA EM C
Autômato celular criado em C como um trabalho de programação no início de 2019.

## Desenvolvedores
[Bernardo Mesko](https://github.com/Bemesko)

[Bárbara Mafra](https://github.com/BarbaraMafra)

## Rodando este Código

### Usando Docker

Basta rodar o comando abaixo (adicione suas flags preferidas se quiser):

```bash
docker run -it --rm bemesko/jogo-da-vida
```

### Na Marra

1. Tenha um compilador de C na sua máquina (nesse caso o GCC)
2. Entre nesse diretório e rode o seguinte comando:

```bash
gcc -o JogoDaVida JogoDaVida.c
```

3. Para executar o programa, apenas rode o comando abaixo:

```bash
./JogoDaVida
```