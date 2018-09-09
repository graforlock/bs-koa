open Koa;
open KoaRoute;
open KoaWebsocket; 

let app = App.make ();
let route = Route.route;
let ws: Socket.ctx(string, string) = Socket.ws(app);

let opts: Route.options = [||];

App.use(app, (ctx, next) => {
  ctx##body #= "Hello World!";
  next();
});

App.use(app,
  Route.get(route, "/:meal", (ctx, param) => {
    ctx##body #= {j|Yummy $param!|j};
  }, ~opts=opts)
);

Socket.use(ws, (ctx, next) => {
  Socket.onMessage(ctx, msg => Js.log(msg) |> ignore);
  Socket.send(ctx, "Hello world!");
  next();
});

App.listen(app, ~port=3000, ~callback=_ => Js.log({j|Listening on port 3000|j}));
