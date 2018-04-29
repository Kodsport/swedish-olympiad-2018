mkdir -p attachments/
for A in {1..10}; do
	cp data/secret/grupp$A/$A.in attachments/$A.in
done
