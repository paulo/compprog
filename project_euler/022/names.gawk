BEGIN           { 
					FS=","; 
					total_name_count=0;
					total=0; 
					for(n=0;n<256;n++) ord[sprintf("%c",n)]=n;
				}
NR==1           { 
					print "A processar o ficheiro: " FILENAME 
				}
				{ 
					for(i=1;i<=NF;i++) {
						data[i]=$i;
					}
				
					n=asort(data); 

					for(k=1;k<=NF;k++) {
						name_count=0;
						for(l=0;l<length(data[k])-2;l++){
							o=substr(data[k],2+l,1);
							name_count+=ord[o]-64;
						}
						aux=name_count*k;
						total+=aux;
					}
				}
END             { print "Total - " total  }