docker stop adrc
docker run -d -v "$PWD/code":/home/code --name="adrc" -it --rm adrc-image
./scripts/getInDocker.sh
