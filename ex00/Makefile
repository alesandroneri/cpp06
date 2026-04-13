NAME = convert

SRC = src/ScalarConverter.cpp \
	src/main.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

.cpp.o:
	$(CXX) $(FLAGS) -c $< -o $(<:.cpp=.o)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: $(NAME)
	@echo "\n=== INICIANDO BATERIA DE TESTES COMPLETA ===\n"
	@echo "--- 1. CHAR LITERALS ---"
	@echo "[Teste 1.1] 'a'" ; ./$(NAME) a ; echo "------------------------"
	@echo "[Teste 1.2] '*'" ; ./$(NAME) \* ; echo "------------------------"
	@echo "\n--- 2. INT LITERALS ---"
	@echo "[Teste 2.1] '0'" ; ./$(NAME) 0 ; echo "------------------------"
	@echo "[Teste 2.2] '42'" ; ./$(NAME) 42 ; echo "------------------------"
	@echo "[Teste 2.3] '-42'" ; ./$(NAME) -42 ; echo "------------------------"
	@echo "[Teste 2.4] '2147483647' (INT_MAX)" ; ./$(NAME) 2147483647 ; echo "------------------------"
	@echo "[Teste 2.5] '-2147483648' (INT_MIN)" ; ./$(NAME) -2147483648 ; echo "------------------------"
	@echo "[Teste 2.6] '2147483648' (Over INT_MAX)" ; ./$(NAME) 2147483648 ; echo "------------------------"
	@echo "[Teste 2.7] '-2147483649' (Under INT_MIN)" ; ./$(NAME) -2147483649 ; echo "------------------------"
	@echo "\n--- 3. FLOAT LITERALS ---"
	@echo "[Teste 3.1] '0.0f'" ; ./$(NAME) 0.0f ; echo "------------------------"
	@echo "[Teste 3.2] '42.42f'" ; ./$(NAME) 42.42f ; echo "------------------------"
	@echo "[Teste 3.3] '-42.42f'" ; ./$(NAME) -42.42f ; echo "------------------------"
	@echo "[Teste 3.4] '2147483648.0f' (Over INT_MAX in float)" ; ./$(NAME) 2147483648.0f ; echo "------------------------"
	@echo "\n--- 4. DOUBLE LITERALS ---"
	@echo "[Teste 4.1] '0.0'" ; ./$(NAME) 0.0 ; echo "------------------------"
	@echo "[Teste 4.2] '42.42'" ; ./$(NAME) 42.42 ; echo "------------------------"
	@echo "[Teste 4.3] '-42.42'" ; ./$(NAME) -42.42 ; echo "------------------------"
	@echo "[Teste 4.4] '2147483648.0' (Over INT_MAX in double)" ; ./$(NAME) 2147483648.0 ; echo "------------------------"
	@echo "\n--- 5. PSEUDO LITERALS ---"
	@echo "[Teste 5.1] 'nan'" ; ./$(NAME) nan ; echo "------------------------"
	@echo "[Teste 5.2] 'nanf'" ; ./$(NAME) nanf ; echo "------------------------"
	@echo "[Teste 5.3] 'inf'" ; ./$(NAME) inf ; echo "------------------------"
	@echo "[Teste 5.3] '+inf'" ; ./$(NAME) +inf ; echo "------------------------"
	@echo "[Teste 5.4] '-inf'" ; ./$(NAME) -inf ; echo "------------------------"
	@echo "[Teste 5.5] 'inff'" ; ./$(NAME) inff ; echo "------------------------"
	@echo "[Teste 5.5] '+inff'" ; ./$(NAME) +inff ; echo "------------------------"
	@echo "[Teste 5.6] '-inff'" ; ./$(NAME) -inff ; echo "------------------------"
	@echo "\n--- 6. INVALID FORMATS & EDGE CASES ---"
	@echo "[Teste 6.1] 'abc'" ; ./$(NAME) abc ; echo "------------------------"
	@echo "[Teste 6.2] '42..0f'" ; ./$(NAME) 42..0f ; echo "------------------------"
	@echo "[Teste 6.3] '42.42.42'" ; ./$(NAME) 42.42.42 ; echo "------------------------"
	@echo "[Teste 6.4] '++'" ; ./$(NAME) ++ ; echo "------------------------"
	@echo "[Teste 6.5] '42a'" ; ./$(NAME) 42a ; echo "------------------------"
	@echo "[Teste 6.6] '42+'" ; ./$(NAME) 42+ ; echo "------------------------"
	@echo "[Teste 6.7] '42.0ff'" ; ./$(NAME) 42.0ff ; echo "------------------------"
	@echo "[Teste 6.8] '42.f'" ; ./$(NAME) 42.f ; echo "------------------------"
	@echo "[Teste 6.9] '42..0'" ; ./$(NAME) 42..0 ; echo "------------------------"
	@echo "[Teste 6.10] '+-42' (Sinais invertidos)" ; ./$(NAME) +-42 ; echo "------------------------"
	@echo "[Teste 6.11] '-+42' (Sinais invertidos)" ; ./$(NAME) -+42 ; echo "------------------------"
	@echo "[Teste 6.12] '42-42' (Sinais inseridos no meio)" ; ./$(NAME) 42-42 ; echo "------------------------"
	@echo "[Teste 6.13] '.0f' (Começa no ponto, é valido)" ; ./$(NAME) .0f ; echo "------------------------"
	@echo "[Teste 6.14] '.' (Somente o ponto solitario)" ; ./$(NAME) . ; echo "------------------------"
	@echo "[Teste 6.15] '.f' (Ponto solto com f)" ; ./$(NAME) .f ; echo "------------------------"
	@echo "[Teste 6.16] 'f' (Letra f solta)" ; ./$(NAME) f ; echo "------------------------"
	@echo "[Teste 6.17] 'ff' (Duplo f)" ; ./$(NAME) ff ; echo "------------------------"
	@echo "[Teste 6.18] '1e10' (Cientifica rejeitada)" ; ./$(NAME) 1e10 ; echo "------------------------"
	@echo "[Teste 6.19] '\"\"' (Literal Vazio)" ; ./$(NAME) "" ; echo "------------------------"
	@echo "[Teste 6.20] ' 42' (Espaco no inicio)" ; ./$(NAME) " 42" ; echo "------------------------"
	@echo "[Teste 6.21] '42 ' (Espaco no final)" ; ./$(NAME) "42 " ; echo "------------------------"
	@echo "\n=== TESTES CONCLUIDOS ==="

.PHONY: all clean fclean re test
