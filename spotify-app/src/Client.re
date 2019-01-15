/* Create an InMemoryCache */
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

/* Create an HTTP Link */
let httpLink =
  ApolloLinks.createHttpLink(
    ~uri=
      "https://serve.onegraph.com/dynamic?app_id=bafd4254-c229-48c2-8c53-44a01477a43e",
    ~credentials="include",
    (),
  );

let authLink =
  ApolloLinks.createContextLink(() => {"headers": OneGraphAuth.authHeaders});

let instance =
  ReasonApollo.createApolloClient(
    ~link=ApolloLinks.from([|httpLink, authLink|]),
    ~cache=inMemoryCache,
    (),
  );
