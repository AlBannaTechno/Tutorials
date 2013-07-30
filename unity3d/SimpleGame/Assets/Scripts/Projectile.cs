using UnityEngine;
using System.Collections;

public class Projectile : MonoBehaviour
{
    public float ProjectileSpeed;
    public GameObject ExplosionPrefab;

    private Enemy _enemy;

    void Start()
    {
        _enemy = (Enemy) GameObject.Find("Enemy").GetComponent("Enemy");
    }
	
	void Update () 
    {
	    // movement
        var amountToMove = ProjectileSpeed * Time.deltaTime;

        transform.Translate(Vector3.up * amountToMove);

        // Destroy when out of vision range
	    if (transform.position.y >= 6.4f)
	        Destroy(gameObject);
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.tag != "Enemy") return;

        Instantiate(ExplosionPrefab, _enemy.transform.position, _enemy.transform.rotation);

        _enemy.MinSpeed += 1.2f;
        _enemy.MaxSpeed += 1.9f;
        _enemy.Spawn();
        Destroy(gameObject);

        Player.Score += 100;

        if (Player.Score >= 1000)
            Application.LoadLevel(3);
    }
}
