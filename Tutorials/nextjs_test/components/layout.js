import styles from "./layout.module.css"
import utilStyles from "../styles/utils.module.css"
import Head from "next/head"
import Image from "next/image"
import Link from "next/link";

const name = "Theseus"
export const siteTitle = "Next JS Test Website"

export default function Layout({ children, home }) {
return (
<div className={styles.container}>
    <Head>
        <link rel="icon" href="/favicon.ico" />
        <meta
            name = "description"
            content = "testing out Next JS"
        />
    </Head>

    <header className = {styles.header}>
        {home ? (
            <>
            <Image
                priority
                src = "/images/profile.jpg"
                className = {utilStyles.borderCircle}
                height = {144}
                width = {144}
                alt = {name}
            />
            <h1 className = {utilStyles.heading2x1}>{name}</h1>
            </>
        ) : (

        <>
        <Link href="/">
            <a>
                <Image
                    priority
                    src = "/images/profile.jpg"
                    className = {utilStyles.borderCircle}
                    height = {108}
                    width = {108}
                    alt = {name}
                />
            </a>
        </Link>
            <h2 className = {utilStyles.headingLg}>
                <Link href="/">
                    <a className = {utilStyles.colorInherit}>{name}</a>
                </Link>
            </h2>
        </>
        )}
    </header>

    <main>{children}</main>
    {!home && (
        <div className={styles.backToHome}>
            <Link href="/">
                <a>Back to Home</a>
            </Link>
        </div>
    )}
</div>
);
}