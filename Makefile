all: clean parallelization.pdf

parallelization.pdf: $(FIGURES)
	pdflatex parallelization
	pdflatex parallelization

clean:
	rm -f parallelization.aux parallelization.log parallelization.nav parallelization.out parallelization.pdf parallelization.snm parallelization.toc
