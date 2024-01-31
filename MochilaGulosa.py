#mochila que aceita quantidades flutuantes de cada item
def mochila(itens,peso_disponivel):
    #itens[preço,kg]
    
    #calcula preco por kg de cada item
    precos=[preco/kg for preco,kg in itens]
    
    #coloca identificador de cada item, e então ordena pelo mais valioso
    precos=[[preco,i] for i,preco in enumerate(precos)]
    precos=sorted(precos,key=lambda i:i[0],reverse=True)
    
    #quantidade em kg pego de cada item
    pego=[0 for i in itens]
    
    #percorre todos os itens disponiveis, até o menos valioso
    for preco_kg,posicao_item in precos:
        #verifica se é possível pegar tudo disponível daquele item
        if  itens[posicao_item][1]<= peso_disponivel:
            pego[posicao_item]=itens[posicao_item][1]
            peso_disponivel-=itens[posicao_item][1]
            
        #pega o máximo que o peso permite
        else:
            pego[posicao_item]=peso_disponivel
            peso_disponivel=0
        
        #mochila cheia
        if peso_disponivel == 0:
            break 
        
    return pego
    
print(mochila([[10,10],[5,6],[8,5]],7))
print(mochila([[70,7],[8,5],[10,10]],7))
print(mochila([[5,6],[10,9],[8,5],[8,8]],70))
