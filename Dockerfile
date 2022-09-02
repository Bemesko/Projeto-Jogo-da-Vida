FROM gcc:12.2.0 as compile

WORKDIR /opt
COPY JogoDaVida.c /opt/JogoDaVida.c
RUN gcc -o JogoDaVida JogoDaVida.c

ENTRYPOINT ["/opt/JogoDaVida"]