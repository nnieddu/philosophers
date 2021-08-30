# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 12:04:59 by ninieddu          #+#    #+#              #
#    Updated: 2021/06/29 06:34:08 by ninieddu         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -rf

INCS_DIR = incs
VPATH = srcs
OBJS_DIR = objs

HEADERS = $(wildcard $(INCS_DIR)/*.h)
SRCS = $(wildcard $(VPATH)/*.c)
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

$(NAME) : $(LIBFT_FILE) $(HEADERS) $(OBJS)
	$(CC) $(CFLAGS) -I $(INCS_DIR) $(OBJS) -o $@

.PHONY: all clean fclean re




number_of_philosophers 
time_to_die
time_to_eat time_to_sleep 
number_of_times_each_philosopher_must_eat

◦ number_of_philosophers: is the number of philosophers and also the number
of forks
◦ time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’
milliseconds after starting his last meal or the beginning of the simulation, it
dies
3Philosophers
I’ve never thought philosophy would be so deadly.
◦ time_to_eat: is in milliseconds and is the time it takes for a philosopher to
eat. During that time he will need to keep the two forks.
◦ time_to_sleep: is in milliseconds and is the time the philosopher will spend
sleeping.
◦ number_of_times_each_philosopher_must_eat: argument is optional, if all
philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the
simulation will stop. If not specified, the simulation will stop only at the death
of a philosopher.




Guidelines


- Ne notez que ce qui est contenu dans le dossier git cloné de l'étudiant
ou du groupe.

- Vérifiez que le dossier git de appartient bien à l'étudiant ou au groupe,
que le projet correspond bien, et que "git clone" est utilisé sur un dossier vide.

- Vérifiez scrupuleusement qu'aucun alias n'a été utilisé pour vous tromper et assurez
vous que vous corrigez bien le rendu officiel.

- Afin d'éviter toute surprise, vérifiez avec l'évalué les potentiels scripts
utilisés pour faciliter l'évaluation.

- Si, en temps qu'évaluateur, vous n'avez pas fait le projet courant, vous devez
lire le sujet en entier avant de commencer l'évaluation.

- Utilisez les flags disponibles pour signaler un rendu vide, un programme ne fonctionnant pas,
une erreur de norme, un problème de triche... Dans ces situations, l'évaluation est terminée
et la note est 0 (ou -42 en cas de triche). Cependant, à l'exception des cas de triche,
vous êtes encouragés à continuer la discussion sur le travail rendu (même si pas terminé)
pour identifier les problèmes qui ont causé cet échec et éviter de les reproduire dans le futur.

- Pendant toute la durée de l'évaluation, aucun segfault ou autre arrêt
du programme (inattendu, prémature ou incontrôlé) ne sera toléré. Dans ces cas-là,
la note finale est 0. Utilisez le flag approprié.
Vous ne devriez jamais avoir à éditer un fichier mis à part un fichier de configuration,
si celui-ci existe. Dans le cas ou vous souhaitez modifier un fichier, vous devez expliciter
clairement les raisons de l'édition et entre en accord avec l'étudiant évalué avant de faire
quoi que ce soit.

- Il vous revient également de vérifier l'absence de fuite mémoire. Toute mémoire allouée
sur la heap doit être proprement libérée avant la fin de l'éxecution.
Vous pouvez pour cela utiliser les différents outils présent sur l'ordinateur,
tels que leaks, valgrind, ou encore e_fence. En cas de fuite mémoire, cochez le flag approprié.
Attachments
subject.pdf
Partie obligatoire

Philo_one code

- Verifiez que le code de philo_one respecte les points suivants et demandez des explications:
- Verifiez qu'il y a un thread par philosophe
- Verifiez qu'il y a une mutex par fourchette, et qu'elle est utilisée pour vérifier la valeur de la fourchette et/ou la changer
- Vérifiez que l'output est protégé contre les accès multiples afin d'éviter un rendu mélangé
- Vérifiez que la mort d'un philosophe est notée et qu'il y a un mutex empêchant le philosophe de mourrir et de commencer a manger exactement au meme moment.
Philo_one test

- Ne testez pas avec plus de 200 philosphes
- Ne testez pas avec time_to_die ou time_to_eat ou time_to_sleep avec une valeur de moins de 60 ms
- Testez avec 5 800 200 200. Personne ne devrait mourir.
- Testez avec 5 800 200 200 7. Personne ne devrait mourir et la simulation devrait s'arreter quand les philosophes ont mangé au moins 7 fois chacun.
- Testez avec 4 410 200 200. Personne ne devrait mourir.
- Testez avec 4 310 200 100. Un philosophe devrait mourir.
- Testez avec 2 philosophes et vérifiez les timings (une mort délayée de plus de 10ms est innacceptable).
- Testez avec vos propres valeurs et vérifiez les règles. Vérifiez que les philosophes meurent au bon moment, qu'ils ne volent pas de fourchette, etc.
Philo_two code

- Verifiez que le code de philo_two respecte les points suivants et demandez des explications:
- Verifiez qu'il y a un thread par philosophe
- Vérifiez qu'il y a un unique semaphore qui représente le nombre de fourchettes
- Vérifiez que l'output est protégé contre les accès multiples afin d'éviter un rendu mélangé
- Vérifiez comment la mort d'un philosophe est vérifiée, et qu'il y a un semaphore empêchant le philosophe de mourrir et de commencer a manger exactement au meme moment.
Philo_two test

- Ne testez pas avec plus de 200 philosphes
- Ne testez pas avec time_to_die ou time_to_eat ou time_to_sleep avec une valeur de moins de 60 ms
- Testez avec 5 800 200 200. Personne ne devrait mourir.
- Testez avec 5 800 200 200 7. Personne ne devrait mourir et la simulation devrait s'arreter quand les philosophes ont mangé au moins 7 fois chacun.
- Testez avec 4 410 200 200. Personne ne devrait mourir.
- Testez avec 4 310 200 100. Un philosophe devrait mourir.
- Testez avec 2 philosophes et vérifiez les timings (une mort délayée de plus de 10ms est innacceptable).
- Testez avec vos propres valeurs et vérifiez les règles. Vérifiez que les philosophes meurent au bon moment, qu'ils ne volent pas de fourchette, etc
Philo_three code

- Verifiez que le code de philo_three respecte les points suivants et demandez des explications:
- Verifiez qu'il y a un process par philosophe et que le process initial les attend tous.
- Vérifiez qu'il y a un unique semaphore qui représente le nombre de fourchettes
- Vérifiez que l'output est protégé contre les accès multiples afin d'éviter un rendu mélangé
- Vérifiez comment la mort d'un philosophe est vérifiée, et qu'il y a un semaphore empêchant le philosophe de mourrir et de commencer a manger exactement au meme moment.
Philo_three test

- Ne testez pas avec plus de 200 philosphes
- Ne testez pas avec time_to_die ou time_to_eat ou time_to_sleep avec une valeur de moins de 60 ms
- Testez avec 5 800 200 200. Personne ne devrait mourir.
- Testez avec 5 800 200 200 7. Personne ne devrait mourir et la simulation devrait s'arreter quand les philosophes ont mangé au moins 7 fois chacun.
- Testez avec 4 410 200 200. Personne ne devrait mourir.
- Testez avec 4 310 200 100. Un philosophe devrait mourir.
- Testez avec 2 philosophes et vérifiez les timings (une mort délayée de plus de 10ms est innacceptable).
- Testez avec vos propres valeurs et vérifiez les règles. Vérifiez que les philosophes meurent au bon moment, qu'ils ne volent pas de fourchette, etc