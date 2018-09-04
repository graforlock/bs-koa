open Koa;
open Route;

let app = App.make ();
let route = Route.route;

let middleware = (_, next) => {
  next();
};

let opts: Route.options = ref([]);

App.use(app, middleware);
App.use(app, 
  Route.get(route, "/", (ctx, next) => {
    ctx##body #= "Huh";
    next();
  }, ~opts=opts)
);

App.listen(app, ~port=3000, ~callback=_ => Js.log({j|Listening on port 3000|j}));
