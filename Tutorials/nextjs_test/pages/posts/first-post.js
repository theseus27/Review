import Link from "next/link";
import Head from "next/head";
import Script from "next/script";
import Layout from "../../components/layout"

export default function Post() {
    return (
    <Layout>
    <Head>
        <title>First Post</title>
    </Head>
    
    {/* Script Example
    <Script
        src = "https://connect.facebook.net/en_US/sdk.js"
        strategy = "lazyOnload"
        onLoad={() =>
            console.log("Facebook script loaded.")
        }
    />
    */}

    <h1>This is a Post</h1>
    <h2>
        <Link href="/">
            <a>Back to Home</a>
        </Link>
    </h2>
    </Layout>
    );
}