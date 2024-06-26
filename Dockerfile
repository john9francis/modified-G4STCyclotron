FROM john9francis/stcyclotron:latest

WORKDIR /home/

RUN wget -O release.tar.gz https://github.com/john9francis/modified-G4STCyclotron/archive/refs/tags/v0.1.4.tar.gz \
&& tar -xzf release.tar.gz && rm release.tar.gz && mv modified-G4STCyclotron-0.1.4/ modified_cyclotron

WORKDIR /home/modified_cyclotron/build/

RUN cmake -DCMAKE_INSTALL_PREFIX=/home/modified_cyclotron/build/program_files/ ..

RUN make -j5

COPY run.sh /home/modified_cyclotron/build/
RUN chmod -x /home/modified_cyclotron/build/