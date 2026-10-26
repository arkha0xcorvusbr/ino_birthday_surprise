import serial
import subprocess
import os

porta_arduino = 'COM5' # Escolha a porta USB que você irá usar.
baud_rate = 9600

try:
    # Estabelecer conexão com a placa.
    conexao = serial.Serial(porta_arduino, baud_rate)
    
    while True:
        if conexao.in_waiting > 0:
            mensagem = conexao.readline().decode('utf-8').strip()
            
            if mensagem == "EXECUTAR_SCRIPT":
                # os.startfile(r"Caminho da imagem") Caso queira abrir uma imagem.
                subprocess.run(["python", r"Caminho do código"]) # Insira o path do código arduíno.
                
except serial.SerialException:
    print("Erro: Não foi possível conectar ao Arduino.")