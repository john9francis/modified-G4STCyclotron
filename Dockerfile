FROM john9francis/stcyclotron:latest

WORKDIR /home/modified_cyclotron/

COPY . /home/modified_cyclotron/

WORKDIR /home/modified_cyclotron/build/

RUN cmake -DCMAKE_INSTALL_PREFIX=/home/modified_cyclotron/build/program_files/ ..

RUN make -j5

COPY run.sh /home/modified_cyclotron/build/
RUN chmod -x /home/modified_cyclotron/build/