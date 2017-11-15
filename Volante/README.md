# Eagle Sensors Project 

## Volante

### Descrizione del Repository 

In questa cartella sono contenuti tutti i file per far girare l'interfaccia del volante. 
Questa funziona in due modalità:

* **Desktop**: compilata per PC Desktop (architettura x86), serve per il debug, per il testing e per la prototipazione veloce, anche quando non dovesse essere disponibile il Raspberry. 
* **Embedded**: cross-compilata per Raspberry Pi 2/Zero W, viene compilata sul PC Host (il desktop) e poi mandata al Raspberry via SSH dove viene lanciato l'eseguibile (per piattaforma ARM). 

**ATTENZIONE**: L'eseguibile compilato per ARM ***non funziona*** su macchina Intel/AMD x86, è necessario inviarla al sistema Embedded e quindi eseguirla in quel contesto. 

### Descrizione Tecnica 




