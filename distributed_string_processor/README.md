# **Distributed String Processor - gRPC + FastAPI**

Um sistema distribuído que processa strings em duas etapas:
1. Converte para maiúsculas (Servidor A - C++)
2. Inverte a string (Servidor B - C++)
3. Interface web via FastAPI (Python)

## **Pré-requisitos**
- Python 3.10+
- g++ (compilador C++)
- pip
- virtualenv (opcional)

## **Instalação**

### **1. Ambiente Virtual (Recomendado)**
```bash
python -m venv venv
source venv/bin/activate  # Linux/Mac
# .\venv\Scripts\activate  # Windows
```

### **2. Dependências Python**
```bash
pip install grpcio==1.58.0 grpcio-tools protobuf==3.20.3 fastapi uvicorn
```

### **3. Compilar Servidores C++**
Na raiz do projeto:
```bash
make clean  # Limpeza prévia
make all    # Compila server_a e server_b
```

## **Execução**

### **1. Iniciar Servidores**
Em **terminais separados**:

#### Servidor A (Uppercase)
```bash
./server_a
```

#### Servidor B (Reverse)
```bash
./server_b
```

### **2. Iniciar Interface Web**
```bash
cd grpc_stub
uvicorn web_server:app --reload
```

Acesse no navegador:  
🔗 [http://localhost:8000](http://localhost:8000)

---

## **Estrutura do Projeto**
```
distributed_string_processor/
├── proto/                    # Arquivos .proto
├── grpc_stub/                # Código Python (FastAPI + gRPC)
│   ├── client.py             # Cliente gRPC
│   ├── web_server.py         # API FastAPI
│   └── templates/            # Frontend HTML
├── cpp_server_a/             # Servidor A (Uppercase)
├── cpp_server_b/             # Servidor B (Reverse)
└── Makefile                  # Compilação automática
```

## **Comandos Úteis**

- **Recompilar protobuf**:
  ```bash
  python -m grpc_tools.protoc -Iproto --python_out=grpc_stub --grpc_python_out=grpc_stub proto/string_processor.proto
  ```

- **Reinstalar dependências**:
  ```bash
  pip install -r grpc_stub/requirements.txt --force-reinstall
  ```

- **Desativar ambiente virtual**:
  ```bash
  deactivate
  ```

---

## **Contato**
Se encontrar problemas, abra uma **issue** no repositório ou entre em contato.

**Exemplo de Uso**:  
Digite `"hello"` no navegador → Retorna `"OLLEH"` (uppercase + reverse).
