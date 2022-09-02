FROM gcc:12.2.0

COPY JogoDaVida.c /opt/JogoDaVida.c

WORKDIR /opt

RUN gcc -o JogoDaVida JogoDaVida.c

ENTRYPOINT ["./JogoDaVida"]