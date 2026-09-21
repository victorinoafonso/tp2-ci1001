# TP2 — Programação 1 (CI1001)

Implementação do **Trabalho Prático 2 (TP2)** da disciplina **CI1001 — Programação 1**, do Departamento de Informática da **Universidade Federal do Paraná (UFPR)**.

## 📚 Sobre o trabalho

O TP2 consiste na adaptação e implementação de um **Tipo Abstrato de Dados (TAD) para números racionais**, utilizando parâmetros por endereço em algumas funções.

O programa trabalha com um vetor de números racionais e realiza operações como:

* Leitura de números racionais;
* Validação de racionais;
* Simplificação de frações;
* Impressão de racionais;
* Remoção de elementos inválidos;
* Ordenação do vetor;
* Soma dos elementos do vetor.

## 🗂️ Estrutura do projeto

```text
tp2/
├── racional.h
├── racional.c
├── tp2.c
└── makefile
```

### Arquivos

| Arquivo      | Descrição                                           |
| ------------ | --------------------------------------------------- |
| `racional.h` | Interface do TAD racional fornecida pela disciplina |
| `racional.c` | Implementação das funções do TAD racional           |
| `tp2.c`      | Programa principal e funções auxiliares             |
| `makefile`   | Arquivo utilizado para automatizar a compilação     |

> **Observação:** o arquivo `racional.h` é fornecido pela disciplina e não deve ser alterado.

## ⚙️ Compilação

Dentro do diretório `tp2`, execute:

```bash
make
```

O comando deve gerar o executável:

```text
tp2
```

Para remover os arquivos gerados pela compilação:

```bash
make clean
```

## ▶️ Execução

O programa recebe os dados pela entrada padrão.

Para utilizar um dos arquivos de teste fornecidos pela disciplina:

```bash
./tp2 < entrada1.txt
```

Também é possível executar diretamente:

```bash
./tp2
```

e fornecer os dados pelo terminal.

## 🧮 Funcionalidades implementadas

### TAD racional

O projeto implementa funções para:

* Criar números racionais;
* Obter numerador e denominador;
* Verificar se um racional é válido;
* Sortear números racionais;
* Simplificar racionais;
* Imprimir racionais;
* Comparar racionais;
* Somar racionais;
* Subtrair racionais;
* Multiplicar racionais;
* Dividir racionais.

### Operações sobre o vetor

O programa principal:

1. Lê a quantidade de números racionais;
2. Preenche o vetor;
3. Imprime o vetor original;
4. Remove os racionais inválidos;
5. Imprime o vetor resultante;
6. Ordena o vetor;
7. Imprime o vetor ordenado;
8. Calcula e imprime a soma dos elementos.

## 🧠 Conceitos praticados

* Linguagem C;
* `struct`;
* Tipos Abstratos de Dados (TADs);
* Ponteiros;
* Parâmetros por endereço;
* Vetores;
* Funções;
* Ordenação por **Insertion Sort**;
* Makefile;
* Compilação com GCC.

## 🛠️ Tecnologias

* **Linguagem:** C
* **Compilador:** GCC
* **Build:** Make
* **Ambiente:** Linux

---

**Disciplina:** CI1001 — Programação 1
**Universidade Federal do Paraná — UFPR**

