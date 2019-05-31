#!/bin/bash
for tipo_alg in QC QM3 QPE QI1 QI5 QI10 QNR; do
	for tipo_vetor in Ale OrdC OrdD; do
		for n in `seq 50000 50000 500000`; do
			$1 $tipo_alg $tipo_vetor $n >> out.txt
		done
	done
done
