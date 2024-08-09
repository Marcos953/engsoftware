class Handler:
    def __init__(self):
        self._next_handler = None

    def set_next(self, handler):
        self._next_handler = handler
        return handler

    def handle_request(self, request):
        if self._next_handler:
            self._next_handler.handle_request(request)


class ConcreteHandlerA(Handler):
    def handle_request(self, request):
        if request == 'A':
            print("Handler A processing request A")
        elif self._next_handler:
            self._next_handler.handle_request(request)


class ConcreteHandlerB(Handler):
    def handle_request(self, request):
        if request == 'B':
            print("Handler B processing request B")
        elif self._next_handler:
            self._next_handler.handle_request(request)


class Client:
    def __init__(self):
        self._handler_chain = ConcreteHandlerA()
        self._handler_chain.set_next(ConcreteHandlerB())

    def make_request(self, request):
        self._handler_chain.handle_request(request)


if __name__ == "__main__":
    client = Client()
    client.make_request('A')  # Output: Handler A processing request A
    client.make_request('B')  # Output: Handler B processing request B
    client.make_request('C')  # No output, as there is no handler for request C
