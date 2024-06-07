FROM john9francis/stcyclotron

WORKDIR /home/modified_cyclotron/

COPY . /home/modified_cyclotron/

WORKDIR /home/modified_cyclotron/build/

RUN cmake -DCMAKE_INSTALL_PREFIX=/home/modified_cyclotron/build/program_files/ ..

RUN make -j5